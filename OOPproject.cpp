#include <iostream>
#include <cstring>
#include <typeinfo>
using namespace std;

class Data
{
protected:
    int zi,an;
    char *luna;
public:
    int getZi()
       {
           return zi;
       }
       int getAn()
       {
           return an;
       }
       char* getLuna()
       {
           return luna;
       }
       void setZi(int zi2)
       {
           this->zi = zi2;
       }
       void setAn(int an2)
       {
           this->an = an2;
       }
       void setLuna(char* luna)
     {
         if(this->luna!=NULL)
            delete[] this->luna;
        this->luna=new char[strlen(luna)+1];
        strcpy(this->luna,luna);
     }
    Data()
    {
        zi=0;
        an=0;
        luna=NULL;
    }
    Data(int zi, int an, char* luna)
    {
        this->zi=zi;
        this->an=an;
        this->luna = new char[3];
        for(int i=0;i<3;i++)
            this->luna[i]=luna[i];

    }
    Data(const Data &clona)
    {
        this->zi=clona.zi;
        this->an=clona.an;
        this->luna=new char[3];
    }
    ~Data()
    {
        if(this->luna != NULL)
            delete[] this->luna;
    }
    Data& operator=(const Data& d)
    {
        if(this != &d)
        {
            this -> zi = d.zi;
            this -> an = d.an;
            for(int i=0;i<3;i++)
                this->luna[i]=d.luna[i];

        }

        return *this;
    }

     void citire()
    {   char aux[3];
        cout<<"Zi:";
        cin>>this->zi;
        if(this->zi>31)
            cout<<"Aceasta zi nu este valida!";
        cout<<"An:";
        cin>>this->an;
        cout<<"Luna(Se citesc doar primele 3 caractere din numele lunii):";
        cin>>aux;
         if(this->luna!=NULL)
            delete[] this->luna;
        this->luna=new char[strlen(aux)+1];
        strcpy(this->luna, aux);
        while(this->CalculeazaLuna()==0)
         {cout<<"Aceasta luna nu este valida!"<<'\n';
          cout<<"Luna(Se citesc doar primele 3 caractere din numele lunii):";
          cin>>aux;
         if(this->luna!=NULL)
            delete[] this->luna;
        this->luna=new char[strlen(aux)+1];
        strcpy(this->luna, aux);}

    }
    void afisare()
    {
        cout<<"Zi:"<<this->zi<<'\n';
        cout<<"An:"<<this->an<<'\n';
        cout<<"Luna: ";
        for(int i=0;i<3;i++)
            cout<<this->luna[i];

    }
    friend ostream&operator<<(ostream&out, const Data &d);
    friend istream&operator>>(istream&in, Data &d);
int CalculeazaLuna()
{
    if(strcmp(this->luna,"ian")==0)
        return 1;
    else if (strcmp(this->luna,"feb")==0)
        return 2;
    else if(strcmp(this->luna,"mar")==0)
        return 3;
    else if(strcmp(this->luna,"apr")==0)
        return 4;
    else if(strcmp(this->luna,"mai")==0)
        return 5;
    else if(strcmp(this->luna,"iun")==0)
        return 6;
    else if(strcmp(this->luna,"iul")==0)
        return 7;
    else if(strcmp(this->luna,"aug")==0)
        return 8;
    else if(strcmp(this->luna,"sep")==0)
        return 9;
    else if(strcmp(this->luna,"oct")==0)
        return 10;
    else if(strcmp(this->luna,"noi")==0)
        return 11;
    else if(strcmp(this->luna,"dec")==0)
        return 12;
    else
        return 0;

    }


};


ostream& operator<<(ostream& out,const Data &d)
{
        out<<"Zi:"<<d.zi<<'\n';
        out<<"An:"<<d.an<<'\n';
        out<<"Luna: ";
        for(int i=0;i<3;i++)
            out<<d.luna[i];
}


istream& operator>>(istream&in, Data& d)
{
    char aux[3];
        cout<<"Zi:";
        in>>d.zi;
         while(d.zi>31)
         {cout<<"Aceasta zi nu este valida!"<<'\n';
          cout<<"Zi:";
         in>>d.zi;}
        cout<<"An:";
        in>>d.an;
        cout<<"Luna(Se citesc doar primele 3 caractere din numele lunii):";
        in>>aux;
         if(d.luna!=NULL)
            delete[] d.luna;
        d.luna=new char[strlen(aux)+1];
        strcpy(d.luna, aux);
        while(d.CalculeazaLuna()==0)
         {cout<<"Aceasta luna nu este valida!"<<'\n';
          cout<<"Luna(Se citesc doar primele 3 caractere din numele lunii):";
          in>>aux;
         if(d.luna!=NULL)
            delete[] d.luna;
        d.luna=new char[strlen(aux)+1];
        strcpy(d.luna, aux);}

}


class Angajat
{
protected:
    string nume,prenume;
    float salariu;
    Data data_angajare;
     static int n;
public:
    Angajat()
    {
        n++;
        Data d;
        this -> nume = "blank";
        this -> prenume = "blank";
        this -> salariu = 0;

    }
    Angajat(string nume, string prenume, float salariu)
    {
        n++;
        this -> nume = nume;
        this -> prenume = prenume;
        this -> salariu = salariu;
}
    Angajat(const Angajat &clona)
    {
        this->nume=clona.nume;
        this->prenume=clona.prenume;
        this->salariu=clona.salariu;
        this->data_angajare = clona.data_angajare;
    }
   Angajat& operator=(const Angajat& a)
    {
        if(this != &a)
        {
            this -> nume = a.nume;
            this -> prenume = a.prenume;
            this -> salariu = a.salariu;
            this -> data_angajare = a.data_angajare;
            }

        return *this;
    }
    ~Angajat()
    {

        if(data_angajare.getLuna()!= NULL)
            data_angajare.setLuna("");
    }
    void citire()
    {
        cout<<"Nume:";
        cin>>nume;
        cout<<"Prenume:";
        cin>>prenume;
        cout<<"Salariu:";
        cin>>salariu;
        cout<<"Data angajarii: "<<'\n';
        cin>>data_angajare;

         }
        void afisare()
    {
        cout<<"Nume:"<<this->nume<<'\n';
        cout<<"Prenume:"<<this->prenume<<'\n';
        cout<<"Salariu: "<<this->salariu<<'\n';
        cout<<"Data angajare: "<<this->data_angajare<<'\n';

    }
    virtual ostream& AfisareV(ostream& out)const
    {
        out<<"Nume:"<<this->nume<<'\n';
        out<<"Prenume:"<<this->prenume<<'\n';
        out<<"Salariu: "<<this->salariu<<'\n';
        out<<"Data angajare: "<<this->data_angajare<<'\n';
        return out;
    }
    virtual istream& CitireV(istream& in)
    {
           cout<<"Nume:";
        in>>this->nume;
        cout<<"Prenume:";
        in>>this->prenume;
        cout<<"Salariu:";
        in>>this->salariu;
        cout<<"Data angajarii: "<<'\n';
        in>>this->data_angajare;
        return in;

    }
friend ostream& operator<<(ostream& out, const Angajat& a);
friend istream&  operator>>(istream& in, Angajat& a);

  static int nr_obiecte()
        {
            return n;
        }

};

int Angajat::n;
ostream& operator<<(ostream& out, const Angajat& a)
{
    return a.AfisareV(out);
}

istream&  operator>>(istream& in, Angajat& a)
{
    return a.CitireV(in);
}

class Part_time : public Angajat
{private:
    int nr_ore_zi;
    Data final_contract;
public:
    Part_time(): Angajat()
    {
        this->nr_ore_zi=0;
    }
    Part_time(string nume, string prenume, float salariu, int nr_ore_zi) : Angajat(nume,prenume,salariu)
    {
        this->nr_ore_zi = nr_ore_zi;
    }
    Part_time(const Part_time &clona):Angajat(clona)
    {
       this->nr_ore_zi = clona.nr_ore_zi;
       this->final_contract = clona.final_contract;
    }

    Part_time& operator=(const Part_time& p)
    {


        if(this!=&p)
        {
            Angajat::operator=(p);
            this->nr_ore_zi=p.nr_ore_zi;
            this->final_contract=p.final_contract;


        }
        return *this;

    }
ostream& AfisareV(ostream& out) const
    {
        Angajat::AfisareV(out);
        out<<"Numar ore/ zi: "<<this->nr_ore_zi;
        cout<<'\n';
        cout<<'\n';
        out<<"Data contract final: "<<final_contract;
        return out;
    }
istream& CitireV(istream& in)
{
    Angajat::CitireV(in);
    cout<<"Numar ore/ zi: "<<'\n';
    in>>this->nr_ore_zi;
   while(this->nr_ore_zi>24)
    {
        cout<<"Din pacate, la firma noastra nu se permite distorsionarea spatiului si a timpului pentru a lucra mai mult de 24 h/zi."<<'\n';
        cout<<"Numar ore/zi: ";
        in>>this->nr_ore_zi;
    }
        cout<<'\n';
        cout<<'\n';
    cout<<"Data contract final: "<<'\n';
    in>>this->final_contract;
    while((final_contract.getAn()<data_angajare.getAn()) || (final_contract.getAn()<=data_angajare.getAn() && final_contract.CalculeazaLuna()<data_angajare.CalculeazaLuna())
          || (final_contract.getAn()<=data_angajare.getAn() && final_contract.CalculeazaLuna()<=data_angajare.CalculeazaLuna() && final_contract.getZi()<data_angajare.getZi()))
    {cout<<"Nu se poate termina contractul inainte ca acesta sa fie angajat.";
    cout<<'\n';
        cout<<'\n';
    cout<<"Data contract final: "<<'\n';
    in>>this->final_contract;
    }
    return in;
}

bool TerminaContractul()
{
    if(final_contract.getAn()>=2021)
        return 0;
    else return 1;
}
float PrimaPartTime()
{
    if(TerminaContractul() == 0)
        return salariu;
    else if (final_contract.getAn()==2020 && final_contract.CalculeazaLuna()==12)return (salariu*75)/100;
    else return 0;

}
};

class Permanent : public Angajat
{
protected:
    int nr_minori_intretinere;

public:
    int getNrMinoriIntretinere()
    {
        return nr_minori_intretinere;
    }
    Permanent(): Angajat()
    {
        this->nr_minori_intretinere=0;
    }
    Permanent(string nume, string prenume, float salariu, int nr_minori_intretinere) : Angajat(nume,prenume,salariu)
    {
        this->nr_minori_intretinere = nr_minori_intretinere;
    }
    Permanent(const Permanent &clona):Angajat(clona)
    {
       this->nr_minori_intretinere = clona.nr_minori_intretinere;
    }

    Permanent& operator=(const Permanent& p)
    {


        if(this!=&p)
        {
            Angajat::operator=(p);
            this->nr_minori_intretinere=p.nr_minori_intretinere;


        }
        return *this;

    }
ostream& AfisareV(ostream& out) const
    {
        Angajat::AfisareV(out);
        out<<"Numar minori intretinere: "<<this->nr_minori_intretinere;
        return out;
    }
istream& CitireV(istream& in)
{
    Angajat::CitireV(in);
    cout<<"Numar minori intretinere: "<<'\n';
    in>>this->nr_minori_intretinere;
    return in;
}

int vechime()
{
   int v=0;
    if(data_angajare.CalculeazaLuna()==12 && data_angajare.getZi()==31 && data_angajare.CalculeazaLuna()!=0)
        v=2020-data_angajare.getAn()+1;
    else
        v = 2020 - data_angajare.getAn();
    return v;
}
float prima()
{
    return ((salariu+vechime()*salariu)/100)*nr_minori_intretinere;
}
};

int main()
{


int k=1,order,order2,n;

     cout<<"Hello!Numele meu este Mirea Oana-Gabriela, si am avut de realizat Proiectul 3 :D"<<'\n';

   while(k!=0)
   {
       cout<<"~~~~~~~~~~~~~~~MENIU~~~~~~~~~~~~~~~"<<'\n';
       cout<<"Pentru a citi si a afisa datele a n angajati, apasa 1."<<'\n';
        cout<<"Pentru a citi si a afisa datele unui angajat, apasa 2."<<'\n';
        cout<<"Pentru a citi si a afisa datele unui angajat care lucreaza permanent/part_time, apasa 3."<<'\n';
         cout<<"Pentru a calcula prima unui angajat de sarbatori, apasa 4."<<'\n';
          cout<<"Pentru a vedea numarul curent de angajati, apasa 5."<<'\n';
           cout<<"Pentru a iesi din program, apasa 0."<<'\n';

    cin>>order;

   switch(order)
   {
   case 1:
   {
    cout<<"Numar angajati: "<<'\n';
   cin>>n;
   Angajat* a[n];
   for(int i=0;i<n;i++){
                    cout<<'\n'<<"Pentru a introduce un angajat Permanent apasa 1"<<'\n';
                    cout<<'\n'<<"Pentru a introduce un angajat Part_time apasa 2"<<'\n';
                    cin>>order2;

                if(order2==1){
                        a[i] = new Permanent;
                    }
                else if(order2==2){
                        a[i] = new Part_time;
                    }
                else
                        cout<<"Aceasta optiune nu este valida!";
                      cin>>*a[i];}
                      cout<<'\n';
                       cout<<'\n';
                for(int i=0;i<n;i++){
                    if(typeid(*a[i]) == typeid(Permanent)){
                        cout<<'\n'<<"Angajatul permanent cu indicele "<<i+1<<" este: "<<'\n';
                         cout<<'\n';
                    }
                    else if(typeid(*a[i]) == typeid(Part_time)){
                        cout<<'\n'<<"Angajatul part-time cu indicele "<<i+1<<" este: "<<'\n';
                         cout<<'\n';
                    }
                    else cout<<"Aceasta optiune nu este valida";
                    cout<<*a[i];
                    cout<<'\n';
                }
                break;
   }


   case 2:
   {
     cout<<'\n'<<"Pentru a citi un angajat Permanent apasa 1"<<'\n';
    cout<<'\n'<<"Pentru a citi un angajat Part_time apasa 2"<<'\n';
                cin>>order2;
                if(order2==1){
                    Permanent p;
                    cin>>p;
                    cout<<'\n';
                    cout<<p<<'\n';
                }
                else if(order2==2){
                    Part_time p;
                    cin>>p;
                    cout<<'\n';
                    cout<<p<<'\n';
                }
                else
                    cout<<"Aceasta optiune nu este valida!";
            break;

   }
   case 3:
   {
       cout<<'\n'<<"Pentru a citi un angajat Permanent apasa 1"<<'\n';
        cout<<'\n'<<"Pentru a citi un angajat Part_time apasa 2"<<'\n';
                cin>>order2;
                if(order2==1){
                    Permanent *p= (Permanent*)new Angajat;
                    cin>>*p;
                    cout<<'\n';
                    cout<<*p<<'\n';
                }
                else if(order2==2){
                    Part_time *p=(Part_time*)new Angajat;
                    cin>>*p;
                    cout<<'\n';
                    cout<<*p<<'\n';
                }
                else
                    cout<<"Aceasta optiune nu este valida!";
        break;
   }
   case 4:
   {
     cout<<'\n'<<"Pentru a citi un angajat Permanent apasa 1"<<'\n';
    cout<<'\n'<<"Pentru a citi un angajat Part_time apasa 2"<<'\n';
                cin>>order2;
                if(order2==1){
                    Permanent p;
                    cin>>p;
                    cout<<'\n';
                    cout<<"Prima pentru un angajat permanent in functie de vechime pana pe data de 31 decembrie 2020 si de copii: "<<'\n';
                    cout<<p.prima()<<'\n';
                }
                else if(order2==2){
                    Part_time p;
                    cin>>p;
                    cout<<'\n';
                    cout<<"Prima pentru un angajat part time in functie de luna terminarii contractului sau este: "<<'\n';
                    if(p.PrimaPartTime()!=0)
                        cout<<p.PrimaPartTime()<<'\n';
                    else
                        cout<<"Angajatul nu mai lucreaza la aceasta firma!"<<'\n';
                }
                else
                    cout<<"Aceasta optiune nu este valida!";
            break;
   }
   case 5:
   {            cout<<'\n';
                cout<<Angajat::nr_obiecte()<<'\n';
                break;

   }
   case 0:
   {
    cout<<'\n'<<"EXIT"<<'\n';
    k=0;
    break;
   }
   default:
    {
        cout<<"Aceasta optiune nu este valida!"<<'\n';
    }

   }
   }
    return 0;
}

