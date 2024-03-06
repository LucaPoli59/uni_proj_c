#ifndef BARCHART_H
#define BARCHART_H

#include <QMainWindow>
#include "file_text_stats.h"
#include <QtDataVisualization>

//using namespace QtDataVisualization;//da togliere se si usa su WINDOWS

/*Classe che gestisce il grafico
 *
 * ottiene i dati del file dall'applicazione e gli usa per impostare il grafico
 *
*/
class Barchart : public QMainWindow
{
    Q_OBJECT

    File_text_stats _file_stats;
    Q3DBars* _bars;

public:
    /*
     * costruttore di default
    */
    Barchart(QWidget *parent = nullptr);

    /*
     * costruttore secondario, inizializza la struct interna che contiene i dettagli del file
     *
     * file_stats: strcut di input da cui vengono copiati i dati
    */
    Barchart(File_text_stats file_stats, QWidget *parent = nullptr);

    /*
     * Funzione che setta la variabile _file_stats
     *
     * file_stats: input con cui si setta la variabile interna
    */
    void setFileStats(File_text_stats file_stats);

    /*
     * Funzione che resetta la variabile _file_stats
    */
    void resetFileStats();

    /*
     * Funzione che crea e mostra il grafico in una nuova finestra
    */
    void getGraph();

    ~Barchart();
};
#endif // BARCHART_H
