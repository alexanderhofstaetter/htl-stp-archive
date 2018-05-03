#include "mainwindow.h"
#include "grafik.h"
#include "ui_mainwindow.h"

using namespace std;

#define ESC 27
#define LF 10

void bubble_sort(float a[], float slave1[], float slave2[], int n)
/////////////////////////////////////////////////////////////////////////////
//   sortiert das Array a[] ansteigend nach der Methode Bubble-Sort
//   Import : int a[]      ... Integer-Array
//            int n        ... Anzahl der Feldelemente
/////////////////////////////////////////////////////////////////////////////
{  int i,j;
   for(i=0; i<n; i++)             // nehme i-tes Element,
   {  for(j=i+1; j<n; j++)        // vergleiche mit den restlichen Elementen
      {  if(a[i]<a[j])            // und tausche die Elemente wenn notwendig
         {  float hilf=a[i];
            float hilf1=slave1[i];
            float hilf2=slave2[i];

            a[i]=a[j];
            slave1[i]=slave1[j];
            slave2[i]=slave2[j];

            a[j]=hilf;
            slave1[j]=hilf1;
            slave2[j]=hilf2;
         }
      }
   }
}

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    NMAX = ui->scope->getN();
    samples = ui->scope->getsamples();
    samples2 = ui->scope->getsamples2();

    for (int i=0;i<NMAX;i++)
    {  samples[i]=0;
       samples2[i]=0;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionDatei_laden_triggered()
{
    QFileDialog fd;                                           // Dateidialog instanzieren

    // File Dialog öffnen
    filename = fd.getOpenFileName(this,
                       "Datei öffnen ",                           // Beschriftung
                       "./",                                      // Startverzeichnis
                       " CSV Dateien (*.csv*)");                  // Dateifilter

    // zur Anzeige ins Textfeld ausgeben
    ui->label_15->setText(filename);

    QByteArray ba = filename.toLocal8Bit();
    char *filename_1 = ba.data();
    fstream file(filename_1,ios::in);
    vector<float> vec;

    if (!file)
        cerr << "Can't open file..." << endl;

    while ( !file.eof() )   // Einlesen bis Dateiende
    {
        string row;
        getline(file, row); // Einlesen einer Zeile

        if ( !row.empty() ) // Falls Zeile nicht leer
        {
            istringstream ss(row);      // StringStream zum zerlegen der Zeile
            string temp;

            getline(ss, temp, ',');     // Ersten Wert bis zum Trennzeichen
                                        // einlesen
            do
            {   stringstream convert;   // StringStream für die Konvertierung
                convert << temp;        // Konvertierung
                float dtemp;            // des String
                convert >> dtemp;       // nach float
                vec.push_back(dtemp);   // und einfügen in den vector
                temp.clear();           // String leeren
                getline(ss, temp, ','); // Nächsten Wert einlesen
            } while ( !temp.empty() );  // Falls Temp Leer ist, gibt es keine
        }                               // neuen Werte in der aktuellen Zeile
    }
    file.close();

    float* arr = vec.data();

    float zeit[NMAX],ch1[NMAX],ch2[NMAX];

    for (int i=0,j=6;i<NMAX;i++,j+=3)
    {
        zeit[i] = arr[j];    // Zeit
        ch1[i] = arr[j+1];   // channel 1
        ch2[i] = arr[j+2];   // channel 2

    }
    for(int i=0;i<NMAX;i++)
    //cout << zeit[i] << ch1[i] << ch2[i] << endl; //Werte ausgeben (Debugging)

    bubble_sort(zeit,ch1,ch2,NMAX);        // Arrays sortieren

    for (int i=0;i<NMAX;i++)
    {  samples[i]  = ch1[i]*10;
       samples2[i] = ch2[i]*10;
    }
    ui->scope->update();

    ui->label_mittel->setText(QString::number(array_mittel(ch1,0,NMAX))+" V");
    ui->label_rms->setText(QString::number(array_rms(ch1,0,NMAX))+" V");
    ui->label_ss->setText(QString::number(array_ss(ch1,0,NMAX))+" V");

    ui->label_mittel_3->setText(QString::number(array_mittel(ch2,0,NMAX))+" V");
    ui->label_rms_3->setText(QString::number(array_rms(ch2,0,NMAX))+" V");
    ui->label_ss_3->setText(QString::number(array_ss(ch2,0,NMAX)));
}

float MainWindow::array_mittel(float a[], int n1, int n2)
/////////////////////////////////////////////////////////////////////////////
//   Summe  der Feldelemente des Arrays a berechnen
//   von Index n1 bis Index n2
//   Import : float a[i] ...  Feld
//            int n1     ...  Index 1
//            int n2     ...  Index 2
//   Export : float      ...  Mittelwert
//
///////////////////////////////////////////////////////////
{   float mittel = 0;
    for(int i = n1; i < n2; i++)
        mittel += a[i];
    return mittel/(n2+1-n1);
}

float MainWindow::array_min ( float a[], int n1 , int n2 )
/////////////////////////////////////////////////////////////////////////////
//   Minimum der Feldelemente des Arrays a berechnen
//   von Index n1 bis Index n2
//   Import : float a[i] ...  Feld
//            int n1     ...  Index 1
//            int n2     ...  Index 2
//   Export : float      ...  Minimum
//
///////////////////////////////////////////////////////////
{   float min = a[0];	// vorläufiges Minimum ist erstes Feldelement
    for (int i = n1; i < n2; i++)
        if (min > a[i]) min = a[i];
    return min;
}

float MainWindow::array_max ( float a[], int n1 , int n2 )
/////////////////////////////////////////////////////////////////////////////
//   Maximum (Spitzenwert) der Feldelemente des Arrays a berechnen
//   von Index n1 bis Index n2
//   Import : float a[i] ...  Feld
//            int n1     ...  Index 1
//            int n2     ...  Index 2
//   Export : float      ...  Maximum (Spitzenwert)
//
///////////////////////////////////////////////////////////
{   float max = a[0];	// vorläufiges Maximum ist erstes Feldelement
    for (int i = n1; i < n2; i++)
        if (max < a[i]) max = a[i];
    return max;
}

float MainWindow::array_ss ( float a[], int n1 , int n2 )
/////////////////////////////////////////////////////////////////////////////
//   Spitze-Spitze-Wert der Feldelemente des Arrays a berechnen
//   von Index n1 bis Index n2
//   Import : float a[i] ...  Feld
//            int n1     ...  Index 1
//            int n2     ...  Index 2
//   Export : float      ...  Spitze-Spitze-Wert
//
///////////////////////////////////////////////////////////
{
    return sqrt(array_max(a,n1,n2)*array_max(a,n1,n2)) + sqrt(array_min(a,n1,n2)*array_min(a,n1,n2));
}

float MainWindow::array_rms ( float a[], int n1, int n2 )
/////////////////////////////////////////////////////////////////////////////
//   RMS-Wert ( echter Effektivwert ) der Feldwerte berechnen
//   RMS  =  Wurzel aus dem Mittelwert der Quadrate der Signalwerte (Feldelemente)
//   Import : float a[i] ...  Feld
//            int n1     ...  Index 1
//            int n2     ...  Index 2
//   Export : float      ...  Effektivwert
//
///////////////////////////////////////////////////////////
{   float rms = 0;
    for (int i = n1; i < n2; i++)
        rms = rms + a[i]*a[i];
    return sqrt(rms/(n2+1-n1));
}

