#include <cstdlib>
#include <iostream>

using namespace std;

class KUBAS
{
    private:
        int ***iDuomenys;//** nuoroda i nuorodu masyva (kiek matmenu masyvas turi, tiek reikes ir pointeriu)
        int iIlgis;
        int iPlotis;
        int iAukstis;
    public:
        KUBAS();//konstruktorius
        ~KUBAS();//destruktorius
        void ivesti();
        void show();
};
//==============================================================================
KUBAS::KUBAS()//konstruktorius
{
    int i1, i2, i3;
    darkarta:
    cout << "Constructor of cube asks" << endl;
    cout << "What length will be? ";
    cin >> i1;
    cout << "What width will be? ";
    cin >> i2;
    cout << "What height will be? ";
    cin >> i3;
    if ((i1<1) || (i2<1) || (i3<1))
    {
        cout << "\nMust be above zero \n";
        goto darkarta;
    } // kad neivestume neigiamo eilucius skaiciaus

    iIlgis = i1;
    iPlotis = i2;
    iAukstis = i3;

    iDuomenys = new int**[iIlgis+1]; // 1-as etapas
    for (int i=0; i<=iIlgis; i++)
    {
        iDuomenys[i] = new int*[iPlotis+1]; // 2-as etapas
    }
    for (int i1=0; i1<=iIlgis; i1++)
    {
            for (int i2=0; i2<=iPlotis; i2++)
            {
                iDuomenys[i1][i2] = new int [iAukstis+1]; //3-ias etapas
            }
    }

    for (int i1=0; i1<=iIlgis; i1++)
    {
            for (int i2=0; i2<=iPlotis; i2++)
            {
                for (int i3=0; i3<= iAukstis; i3++)
                {
                    iDuomenys[i1][i2][i3] = 0;
                }
            }
    }

}
//==============================================================================
KUBAS::~KUBAS()//destruktorius
{
    delete iDuomenys;
}
//==============================================================================
void KUBAS::ivesti()
{
    int iu;
    cout << "Fulfillment " << endl;
    for(int i3=1; i3<=iAukstis; i3++)
    {
        cout << i3 << " layer " << endl;
        for(int i1=1; i1<=iIlgis; i1++)
        {
            cout << i1 << " insert a row" << endl;
            for(int i2=1; i2<=iPlotis; i2++)
            {
                cout << i2 << ":";
                cin >> iu;
                iDuomenys[i1][i2][i3] = iu;
            }

        }
    }
}
//==============================================================================
void KUBAS::show()
{
    cout << "Show " << endl;
    cout << "   ";
    for(int i3=1; i3<=iAukstis; i3++)
    {
        cout << "\n"<< i3 << " layer" << endl;
        for(int i1=1; i1<=iIlgis; i1++)
        {
            for (int i2=1; i2<=iPlotis; i2++)
            {
                cout << iDuomenys[i1][i2][i3] << " ";
            }
            cout << endl;
        }
    }
}
//==============================================================================
int main(int argc, char *argv[])
{
    KUBAS c;//iveda vartotojas
    c.ivesti();
    c.show();

    system("pause");
    return EXIT_SUCCESS;
}
