#ifndef WORDCOUNTER_H
#define WORDCOUNTER_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include "file_text_stats.h"
#include "barchart.h"

QT_BEGIN_NAMESPACE
namespace Ui { class WordCounter; }
QT_END_NAMESPACE

/*
 * Struttura dati di appoggio che memorizza tutte le statistiche
 * importati di un file di testo
 *
*/


class WordCounter : public QMainWindow
{
    Q_OBJECT

private:
    Ui::WordCounter *ui;
    File_text_stats _file_text_stats;
    QFile* _file;
    QString _savePath;
    Barchart _barchart;

public:
    WordCounter(QWidget *parent = nullptr);
    ~WordCounter();

    /* Funzione che aggiorna il file e il filename
     *
     * filepath: stringa che contiene il percorso per arrivare al file
    */
    bool updateFile(const QString filepath);

    /* Funzione che aggiorna leggendo dal file le sue statistiche
     *
    */
    void updateFileStats();

    /* Funzione che restituisce le statistiche del file
     *
    */
    File_text_stats getFileStats() const;



private:

    /* Funzione che processa il file leggendolo, ed eliminando i caratteri di escape inutili
     *
     * file_text: varriabile in cui verrà messo il testo letto dal file
     */
    void read_textFile(QString& file_text);

    /* Funzione che processa il testo del file contando i caratteri totali, e quelli esclusi gli spazi
     *
     * file_text: testo letto dal file
     */
    void textFile_processing_nchars(const QString& file_text);

    /* Funzione che processa il testo del file contando le parole, le frasi e i paragrafi
     *
     * file_text: testo letto dal file
     */
    void textFile_processing_syntaxStats(const QString& file_text);

    /* Funzione che scrive in un file csv omonimo le statistiche del file
     *
     * original_folder booleano che indica se usare il folder originale o quello di default
     */
    void write_text_stats(bool orignal_folder) const;

    /* Funzione che resetta a 0 le statistiche del file
     */
    void reset_text_stats();

    /*
     * Funzione che carica il file e i risultati negli spazi appossiti
     *
     * text: testo contenuto nel file
     */
    void updateUi(const QString& text);


private slots:
    /*
     * Funzione che prende i dati dall'interfaccia grafica e aggiorna il file
     *
     * aggiorna poi l'interfaccia
    */
    void on_path_submit_button_clicked();

    /*
     * Funzione che prende i dati dall'interfaccia grafica e aggiorna il file
     *
     * aggiorna poi l'interfaccia
    */
    void on_lineEdit_path_file_returnPressed();

    /*
     * Funzione che mostra il grafico di quei dati nella relativa finestra
    */
    void on_getGraph_button_clicked();

    /*
     * Funzione che permette la ricerca del file nel filesystem
    */
    void on_browse_file_button_clicked();
};
#endif // WORDCOUNTER_H
