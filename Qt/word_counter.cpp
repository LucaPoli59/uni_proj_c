#include "word_counter.h"
#include "ui_word_counter.h"

WordCounter::WordCounter(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WordCounter)
    , _file_text_stats()
    , _file(nullptr)
    , _savePath()
    , _barchart()
{
    //creo se non esiste il folder di output dove verranno salvati di default i csv
    if(!QDir("files_out").exists())
    {
        QDir().mkdir("files_out");
    }

    ui->setupUi(this);
}

WordCounter::~WordCounter()
{
    delete _file;
    delete ui;
}


/* Funzione che processa il file leggendolo, ed eliminando i caratteri di escape inutili
 *
 * file_text: varriabile in cui verrà messo il testo letto dal file
 *
 * pre: controllo sull'apertura del file
 */
void WordCounter::read_textFile(QString& file_text)
{
    if(!_file->open(QIODevice::ReadOnly))//controllo teoricamente superfluo
    {
        file_text = "";
    }
    else
    {
        QTextStream in(_file);
        file_text = in.readAll();//ho letto il file

        //rimuovo dal testo tutti i caratteri di escape tranne \n (usato per ottenere i numero di 'a capo')
        QChar escape_chars[] = {'\a', '\b', '\f', '\r', '\t', '\v', '\0'};
        for (unsigned int i = 0; i < 7 ; i++)
        {
            file_text.remove(escape_chars[i]);
        }

        _file->close();
    }

}

/* Funzione che processa il testo del file contando i caratteri totali, e quelli esclusi gli spazi
 *
 * file_text: testo letto dal file
 */
void WordCounter::textFile_processing_nchars(const QString& file_text)
{
    //il numero di caratteri totali viene ottenuto dalla lunghezza del testo meno il numero di caratteri di escape
    _file_text_stats._nchars_total = file_text.length() - file_text.count("\n");

    //il numero di caratteri senza spazi viene ottenuto dai totali meno il numero di spazi
    _file_text_stats._nchars_nospace =  _file_text_stats._nchars_total - file_text.count(" ");
}

/* Funzione che processa il testo del file contando le parole, le frasi e i paragrafi
 *
 * file_text: testo letto dal file
 */
void WordCounter::textFile_processing_syntaxStats(const QString& file_text)
{
    if(file_text.length() != 0)
    {
        QChar c_prec = file_text.at(0);//c_prec: carattere precedente a quello attuale
        for (int i = 1; i < file_text.length() ;i++ )
        {
            QChar c_curr = file_text.at(i);//c_curr: carattere attuale
            if(c_prec != ' ' and c_prec != '\n')
            {
                if(c_curr == ' ' or c_curr == '\n')
                {
                    //se l'ultimo elemento non era uno spazio (o \n) e il corrente lo è (o \n), allora ho trovato una parola
                    _file_text_stats._nwords++;
                    if(c_prec == '.' or c_prec == '!' or c_prec == '?')
                    {
                        //se l'ultimo elemento era un terminatore di frase e il corrente è uno spazio (o \n), allora ho trovato una frase
                        _file_text_stats._nphrase++;
                        if(c_curr == '\n')
                        {
                            //se l'ultimo elemento era un terminatore di frase e il corrente è un 'a capo', allora ho trovato un paragrafo
                            _file_text_stats._nparagraph++;
                        }
                    }
                    else
                    {   /*****
                         * scelta progettuale, si considera la frase terminata quando si termina anche il paragrafo
                         * in questo modo termiamo la frase anche in caso di errore e mancanza di (. , !, ?)
                         ****/
                        if(c_curr == '\n')
                        {
                            _file_text_stats._nphrase++;
                            _file_text_stats._nparagraph++;
                        }
                    }
                }
            }
            c_prec = c_curr;
        }
        /*scelta progettuale:
         * considero terminate di frase, parola e paragrafo la fine del file
         * (se non sono già state terminate dal'utente)
         */
        if(c_prec != '\n')
        {
            _file_text_stats._nparagraph++;
            _file_text_stats._nphrase++;
            _file_text_stats._nwords++;
        }
    }
}

/* Funzione che scrive in un file csv omonimo le statistiche del file
 *
 *original_folder booleano che indica se usare il folder originale o quello di default
 *
 *default folder: presente nella directory di procetto con il nome di "files_out"
 */
void WordCounter::write_text_stats(bool orignal_folder) const
{
    QString final_save_path;//stringa temporanea che mantiene la path di destinazione

    if(orignal_folder)//la path di destinazione viene determinata da questa opzione
    {
        //escludo l'estensione prevista .txt e la sostituisco con .csv
        final_save_path = _savePath.split('.').first() + ".csv";

    }
    else
    {
        //estraggo il nome, escludendo il percorso precedente, e la sostituisco con il df folder

        //PER USO SU UNIX
        final_save_path = "files_out/" + _savePath.split('/').last().split('.').first() + ".csv";

        //DA SOSTITUIRE SE SIAMO SU WINDOWS
        // final_save_path = "files_out\\" + _savePath.split('\\').last().split('.').first() + ".csv";
    }

    //apro il file e lo scrivo
    QFile file (final_save_path);
    if(!file.open(QIODevice::WriteOnly))
    {
        qCritical() << "Impossibile creare il file: " <<qPrintable(file.errorString());
    }
    else
    {
        QTextStream out (&file);

        //scrivo il risultato nel file csv
        out << "caratteri," << _file_text_stats._nchars_total << "\n";
        out << "caratteri_no_spazi," << _file_text_stats._nchars_nospace << "\n";
        out << "parole," << _file_text_stats._nwords << "\n";
        out << "frasi," << _file_text_stats._nphrase << "\n";
        out << "paragrafi," << _file_text_stats._nparagraph << "\n";
    }

    file.close();
}


/* Funzione che resetta a 0 le statistiche del file
 */
void WordCounter::reset_text_stats()
{
    _file_text_stats._nchars_total = 0;
    _file_text_stats._nchars_nospace = 0;
    _file_text_stats._nwords = 0;
    _file_text_stats._nparagraph = 0;
    _file_text_stats._nphrase = 0;
}


/* Funzione che aggiorna il file e il filename
 *
 * filepath: stringa che contiene il percorso per arrivare al file
 *
 * return: true o false se il file è stato aggiornato con successo o no
*/
bool WordCounter::updateFile(const QString filepath)
{
    //provo ad aprire il file in lettura, per vedere se è valido
    QFile* file = new QFile(filepath);
    if(!file->open(QIODevice::ReadOnly))
    {
        //se non è valido, stampo l'errore e resetto lo stato interno
        qCritical() <<"Errore nell'apertura del file: "<< qPrintable(file->errorString());

        delete file;
        _file = nullptr;
        _savePath = "";
        return false;
    }

    file->close();
    _file = file;
    _savePath = filepath;

    return true;
}

/* Funzione che aggiorna leggendo dal file le sue statistiche
 *
*/
void WordCounter::updateFileStats()
{
    reset_text_stats();//resetto le statistiche del file

    QString file_text;//leggo il file
    read_textFile(file_text);

    //processo il testo
    textFile_processing_nchars(file_text);
    textFile_processing_syntaxStats(file_text);
}

/* Funzione che restituisce le statistiche del file
 *
*/
File_text_stats WordCounter::getFileStats() const
{
    return _file_text_stats;
}

/*
s* Funzione che carica il file e i risultati negli spazi appossiti
*
* text: testo contenuto nel file
*/
void WordCounter::updateUi(const QString& text)
{
    //inserisco il testo nell'apposita area per visualizzarlo
    ui->file_outputArea->setText(text);

    //inserisco il risultato nella tabella
    QTableWidgetItem* tmp_cell;

    tmp_cell = ui->file_stats_table->item(0,0);
    tmp_cell->setText(QString::number(_file_text_stats._nchars_total));
    tmp_cell = ui->file_stats_table->item(1,0);
    tmp_cell->setText(QString::number(_file_text_stats._nchars_nospace));
    tmp_cell = ui->file_stats_table->item(2,0);
    tmp_cell->setText(QString::number(_file_text_stats._nwords));
    tmp_cell = ui->file_stats_table->item(3,0);
    tmp_cell->setText(QString::number(_file_text_stats._nphrase));
    tmp_cell = ui->file_stats_table->item(4,0);
    tmp_cell->setText(QString::number(_file_text_stats._nparagraph));

    //stampo il risultato in console per debug
    qInfo() << "il numero di caratteri totali (senza escape) è: " <<_file_text_stats._nchars_total;
    qInfo() << "il numero di caratteri senza spazi è: " << _file_text_stats._nchars_nospace;
    qInfo() << "il numero di parole è: " << _file_text_stats._nwords;
    qInfo() << "il numero di frasi è: " << _file_text_stats._nphrase;
    qInfo() << "il numero di paragrafi è: " << _file_text_stats._nparagraph <<"\n\n";

    //aggiorno lo stato del grafico a barre
    _barchart.setFileStats(_file_text_stats);
}


/*
 * Funzione che prende i dati dall'interfaccia grafica e aggiorna il file
 *
 * aggiorna poi l'interfaccia
*/
void WordCounter::on_path_submit_button_clicked()
{
    //prendo il percorso dalla lineEdit apposita
    QString pathInput = ui->lineEdit_path_file->text();

    //aggiorno le statistiche
    if(updateFile(pathInput))
    {
        updateFileStats();

        QString tmp_text;
        read_textFile(tmp_text);
        updateUi(tmp_text);

        write_text_stats(ui->original_folder_checkBox->checkState());
    }
    else
    {
        //se non è possibile leggere il file, resetto lo stato della finestra e delle statistiche
        reset_text_stats();
        updateUi("Errore nel caricamento del file");
    }
}

/*
 * Funzione che prende i dati dall'interfaccia grafica e aggiorna il file
 *
 * aggiorna poi l'interfaccia
*/
void WordCounter::on_lineEdit_path_file_returnPressed()
{
    on_path_submit_button_clicked();//effettua la stessa operazione
}

/*
 * Funzione che mostra il grafico di quei dati nella relativa finestra
*/
void WordCounter::on_getGraph_button_clicked()
{
    _barchart.getGraph();//stampo il grafico quando il pulsante viene premuto
}

/*
 * Funzione che permette la ricerca del file nel filesystem
*/
void WordCounter::on_browse_file_button_clicked()
{
    //avvio un file Dialog per la ricerca del file
    QString file_path = QFileDialog::getOpenFileName(this, "Apri un file di testo");

    //DA INSERIRE SOLO SE SI USA SU WINDOWS
    //il file dialog restituisce il testo in un formato diverso, così viene adeguato
    //file_path.replace("/", "\\");

    //setto il path_file nella lineEdit apposita, ed effettuo le operazioni
    ui->lineEdit_path_file->setText(file_path);
    on_path_submit_button_clicked();

}

