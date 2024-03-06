#include "barchart.h"
#include "file_text_stats.h"

/*
 * costruttore di default
*/
Barchart::Barchart(QWidget *parent) : QMainWindow(parent), _file_stats(), _bars(nullptr){}

/*
 * costruttore secondario, inizializza la struct interna che contiene i dettagli del file
 *
 * file_stats: strcut di input da cui vengono copiati i dati
*/
Barchart::Barchart(File_text_stats file_stats, QWidget *parent) : QMainWindow(parent), _file_stats(file_stats), _bars(nullptr){}

Barchart::~Barchart()
{
    if(_bars != nullptr)
    {
        delete _bars;
    }

}


/*
 * Funzione che setta la variabile _file_stats
 *
 * file_stats: input con cui si setta la variabile interna
*/
void Barchart::setFileStats(File_text_stats file_stats)
{
    _file_stats = file_stats;
}

/*
 * Funzione che resetta la variabile _file_stats
*/
void Barchart::resetFileStats()
{
    File_text_stats tmp;
    _file_stats = tmp;
}

/*
 * Funzione che crea e mostra il grafico in una nuova finestra
*/
void Barchart::getGraph()
{
    if(_bars != nullptr)
    {
        delete _bars;
    }
    _bars = new Q3DBars;

    //impostazioni grafiche
    _bars->setMinimumSize(QSize(600, 500));
    _bars->setMaximumSize(QSize(16777215, 16777215));
    _bars->setFlags(_bars->flags() ^ Qt::FramelessWindowHint);
    _bars->rowAxis()->setRange(0,0);
    _bars->columnAxis()->setRange(0,4);

    //inserimento dei dati
    QBar3DSeries* series = new QBar3DSeries;
    QBarDataRow* data = new QBarDataRow;

    *data << _file_stats._nchars_total << _file_stats._nchars_nospace << _file_stats._nwords
          << _file_stats._nphrase << _file_stats._nparagraph;

    QStringList labels;
    labels << "caratteri totali" << "caratteri (spazi esclusi)" << "parole" << "frasi" << "paragrafi";

    series->dataProxy()->addRow(data);
    _bars->addSeries(series);
    _bars->columnAxis()->setLabels(labels);
    _bars->columnAxis()->setLabelAutoRotation(90);

    _bars->show();
}
