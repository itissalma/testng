#include <iostream>
#include <string>
#include<fstream>
#include <vector>
using namespace std;
const int capacity=100;

class person{//make pure virtual?
private:
    string name;
    string ID;
    int age;
public:
    person(string personname="xxx", string personID="xxx", int personage=18);
    person(const person &p1);//i dont think this is correct--> review copy constructors
    void setname(string personname);
    void setID(string personID);
    void setage(int num);
    string getname() const;
    string getID() const;
    int getage() const;
    virtual void print();
};
person::person(string personname, string personID, int personage){
    name=personname;
    ID=personID;
    age=personage;
};
person ::person (const person &p1){
    name=p1.name;
    ID=p1.ID;
    age=p1.age;
};
void person ::setname(string personname){
    name=personname;
};
void person ::setage(int num){
    age=num;
};
void person ::setID(string personID){
    ID=personID;
};
string person ::getname() const{
    cout<<"this is the getname cout statement\n";
    return name;
};
string person ::getID() const{
    return ID;
};
int person ::getage() const{
    return age;
};
void person ::print(){
    cout<<"This is the print function for the class person\n"
    <<"This person's name is "<<name<<endl
    <<"This person's age is "<<age<<endl
    <<"This person's ID number is "<<ID<<endl;
}
struct appointment{
    int hours=0;
    float minutes=0;
    string name;
    
};
class patient : public person{//multiplicity?????
private:
    string doctorID;
    appointment patientapp;//aggregation or composition
    static int patientcounter;
    string patientname;
public:
    patient(string name="xxx", string ID="xxx", int age=18, int hours=00, int minutes=00);
    bool operator <(const patient &p2);
    bool operator >(const patient &p2);
    bool operator ==(const patient &p2);
    //Overload the <,>,== operators to compare between patients’ appointments.
    void sethours(int hours);
    void setminutes(float minutes);
    int getpathours() const;
    float getpatminutes() const;
    void setdoctorID(string docID);
    string getdoctorID();
    //string getpatientname() const;
    static int getpatientcounter();
    //void setpatientname(string n);
    //string getpatientname() const;
};
/*void patient::setpatientname(string n){
    patientname=n;
}
string patient::getpatientname() const {
    return patientname;
}*/
int patient::patientcounter=0;
int patient::getpatientcounter(){
    return patientcounter;
}
patient ::patient (string name, string ID, int age, int hours, int minutes) :person(name, ID, age){
    patientapp.hours=hours;
    patientapp.minutes=minutes;
    patientcounter++;
};
void patient::sethours(int hours){
    patientapp.hours=hours;
};
void patient::setminutes(float minutes){
    patientapp.minutes=minutes;
};
void patient::setdoctorID(string docID){
    doctorID=docID;
}
int patient ::getpathours() const{
    return (patientapp.hours);
};
float patient ::getpatminutes() const{
    return (patientapp.minutes);
};
string patient::getdoctorID(){
    return doctorID;
};
/*string patient::getpatientname() const{
    return gename;
}*/
bool patient :: operator <(const patient &p2){
    if(patientapp.hours<p2.patientapp.hours){
        return true;
    }
    else
        return false;
}
bool patient :: operator >(const patient &p2){
    if(getpathours()>p2.getpathours()){
        return true;
    }
    else
        return false;
}
bool patient :: operator ==(const patient &p2){
    if(getpathours()==p2.getpathours()){
        return true;
    }
    else
        return false;
}
template <class T>
class queue{//took it from BB and turned it into a template
private:
    int back;
public:
    T container[capacity];
    queue();
    bool enqueue(T x);
    T dequeue();
    bool empty();
    void print ();
    T front(int i);
};
template <class T>
queue<T>::queue() {back = -1;}
template <class T>
T queue<T>::front(int i) {
    return container[i];
}
template <class T>
bool queue<T>::enqueue(T x)
{
    if (back >= (capacity - 1))
        return false;
    else
    {
        back++;
        container[back] = x;
        return true;
    }
}
template <class T>
T queue<T>::dequeue()
{
    if (back < 0){//took this part from a website
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);}
    else
    {
        T x = container[0];
        for (int i = 1; i <= back; i++)
            container[i - 1] = container[i];
        back--;
        return x;
    }
}
template <class T>
bool queue<T>::empty()
{ return (back < 0);}
template <class T>
void queue<T>::print()
{
    for (int i = 0; i <= back; i++)
        cout << container[i] << " ";
    cout << endl;
}
class doctor: public person{
private:
    static int counter;
    //Array of struct (appointment):  that indicates the times the Dr is booked.
    vector<appointment> docapp;
    string patientname;
    int numberofappointments;
    string myname;
public:
    doctor(string name="xxx", string ID="xxx", int age=18, int numofappointments=0);
    ~doctor();
    static int getcounter();
    bool isfree(const patient &p1);
    //void setappointment(int hours, int min)
    void setappointmenthour(int hours, int i);
    void setappointmentminute(float minutes,int i);
    void setdocapp(const patient &p1);
    string getpatientname(int i);
    int gethours(int i) const;
    float getminutes(int i) const;
    int getappnum(int i) const;
    virtual void print(int originalnumofapp);
    void incrementnumofapps();
    void sortalgorithm(doctor arrayofdoctors[]);
    doctor(const doctor&, int j);
    void setpatientname(string name);
    void setdocname(string n);
    string getdocname() const ;
};
void doctor::setdocname(string n){
    myname=n;
}
string doctor::getdocname() const {
    return myname;
}
void doctor::setpatientname(string name){
    patientname=name;
}
  doctor::doctor(const doctor& doc, int j){
    //int i=0;
    setdocname(doc.getdocname());
    setID(doc.getID());
    setage(doc.getage());
    setpatientname(doc.docapp[j].name);
    setappointmenthour(doc.docapp[j].hours, 0);
    setappointmentminute(doc.docapp[j].minutes, 0);
}
int doctor::counter=0;
doctor::doctor(string name, string ID, int age, int numofappointments):person(name, ID, age){
    ++counter;
    numberofappointments=numofappointments;
    cout << "Here1: " << numberofappointments << endl;
    for (int i=0; i<numofappointments;i++){
        docapp.push_back(appointment());
        //docapp[i].name=" ";
    }
    cout<<"the length of the vector is "<<docapp.size()<<endl;
};
void doctor::setdocapp(const patient &p1){
    docapp.push_back(appointment());
    docapp[numberofappointments].name=p1.getname();
    docapp[numberofappointments].hours=p1.getpathours();
    docapp[numberofappointments].minutes=p1.getpatminutes();
    cout<<"the new length of the vector is "<<docapp.size()<<endl;

    
    //for (int i=0; i<numberofappointments;i++){
        //cout<<docapp[i].name<<" has an appointment at "<<docapp[i].hours<<":"<<docapp[i].minutes<<endl;}
}
int doctor::getcounter() {
    return counter;
};
bool doctor::isfree(const patient &p1){ //incorrect syntax--code
    bool aretheyfree=true;
    for(int i=0; i<numberofappointments; i++){
    if (docapp[i].hours==p1.getpathours()&&docapp[i].minutes==p1.getpatminutes())
        aretheyfree=false;
        }

        return aretheyfree;
    };
void doctor::setappointmenthour(int hours, int i){
    docapp[i].hours=hours;
};
void doctor::setappointmentminute(float minutes, int i){
    docapp[i].minutes=minutes;
};

string doctor::getpatientname(int i){
    cout<<"the number sent to the patientname function is "<<i<<endl;
    return (docapp.at(i).name);} // *(docApp + 0)
int doctor::gethours(int i) const{
    return (docapp.at(i).hours);
};
float doctor::getminutes(int i) const{
    return (docapp.at(i).minutes);
};
void doctor::print(int originalnumofapp){
        cout<<(docapp.at(0).name)<<" has an appointment at "<<(docapp.at(0).hours)<<":"<<(docapp.at(0).minutes)<<" with Dr. "<<getdocname()<<endl;
}
void doctor::incrementnumofapps(){
    numberofappointments++;
};
int doctor:: getappnum(int i) const {
    return numberofappointments;
};
doctor::~doctor(){
    docapp.clear();
    --counter;
    cout<<"this is the desctructor\n";
};
template <class T>
void swapswap(T& x,T& y)
{
     T temp;
     temp=x;
     x=y;
     y=temp;
}
//couldn't get the swap template function to work
void doctor ::sortalgorithm(doctor arrayofdoctors[]){
    int i, minidx, j, n;
    n=patient::getpatientcounter();
    cout<<"the patient counter in the operator is "<<n<<endl;
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        minidx = i;
        for (j = i+1; j < n; j++)
    if(arrayofdoctors[i].docapp[0].hours<arrayofdoctors[minidx].docapp[0].hours&&arrayofdoctors[i].docapp[0].minutes<arrayofdoctors[minidx].docapp[0].minutes){
        minidx = j;
        swapswap(arrayofdoctors[i].docapp[0].hours,arrayofdoctors[minidx].docapp[0].hours);
    }
    }};

int main() {
    ifstream inputfile;
    inputfile.open("/Users/salmaaly/Desktop/AUC-xcode/Sample/Sample/instructions");
    if(inputfile.fail())
        cout<<"The file failed to open\n";
    int numofdoctors, numofpatients, temphour, tempage, tempmin, docage, numofappointments, apphour, appmin, appcounter, originalnumberofapp=0;
    string tempname, tempID, docname, tempdocage, docID, tempnumofappointments, tempappointmenthour, tempappointmentmin, end;
    cout<<"How many doctors are currently working in the hospital?\n";
    cin>>numofdoctors;
    cout<<"How many patients are currently waiting in the hospital?\n";
    cin>>numofpatients;
    patient *arrayofpatients=new patient[numofpatients];
    doctor *arrayofdoctors=new doctor[numofdoctors];
    doctor finaldoctorsarray[numofpatients];


    int k=0;
    for (int i=0; i<numofpatients; i++){
        cout<<"Enter the name, ID, and age of Patient #"<<i<<" respectively\n";
        cin>>tempname>>tempID>>tempage;
        cout<<"Enter the hour in which you would like the appointment to take place, using the 24 hour system\n";
        cin>>temphour;
        cout<<"Enter the minute(s) in which you would like the appointment to take place, in 00 form\n";
        cin>>tempmin;
        arrayofpatients[i]=patient(tempname, tempID, tempage, temphour, tempmin);}
        for (int i=0; i<numofdoctors;i++){
        getline(inputfile, docname, ' ');
        getline(inputfile, docID, ' ');
        getline(inputfile, tempdocage, ' ');
        getline(inputfile, tempnumofappointments, ' ');

        docage=stoi(tempdocage);
        numofappointments=stoi(tempnumofappointments);
            originalnumberofapp=numofappointments;
            
        cout<<docname<<" "<<docID<<" "<<" "<<docage<<" "<<tempnumofappointments<<endl;
        
        arrayofdoctors[i]=doctor(docname, docID, docage, numofappointments);

        for (int j=0; j<numofappointments;j++){
            getline(inputfile, tempappointmenthour, ' ');
            getline(inputfile, tempappointmentmin, ' ');
            apphour=stoi(tempappointmenthour);
            appmin=stoi(tempappointmentmin);
            arrayofdoctors[i].setappointmenthour(apphour,i);
            arrayofdoctors[i].setappointmentminute(appmin,i);
            cout<<"the time of the appointment is" <<tempappointmenthour<<":"<<tempappointmentmin<<endl;
        }
        getline(inputfile, end, '\n');}
    do{
        for (int i=0;i<numofdoctors;i++){
        if(arrayofdoctors[i].isfree(arrayofpatients[k])){
            numofappointments=arrayofdoctors[i].getappnum(i);
                arrayofdoctors[i].setdocapp(arrayofpatients[k]);
            
            /*cout<<arrayofdoctors[k].getpatientname(numofappointments)<<" has an appointment at "<<arrayofdoctors[k].gethours(numofappointments)<<":"<<arrayofdoctors[k].getminutes(numofappointments)            <<arrayofdoctors[k].getname()<<endl;*/

                arrayofdoctors[i].incrementnumofapps();
            k++;
            cout<<"doneeee"<<endl;
            }
            else
                cout<<arrayofdoctors[i].getdocname()<<" isn't free\n";
        cout << "Yes hereHere"<<endl;
        }}
    
    while(k<numofpatients);
    cout<<"i am before the primt function"<<endl;

    
    
    for (int i=0; i<numofpatients;i++){ //copies all the appointments into one array
        finaldoctorsarray[i]=doctor(arrayofdoctors[i]);
    }
    finaldoctorsarray->sortalgorithm(finaldoctorsarray); //sorts the appointments in order
    
    queue<doctor> myqueue;
    for (int i=0; i<numofpatients; i++){
        myqueue.enqueue(finaldoctorsarray[i]);
    }
    int i=0;
    while (!myqueue.empty()||i<numofpatients)
      {
          //cout<<myqueue.front(i)<<endl;
          myqueue.dequeue();
          i++;
      }

    
    for (int i=0; i<numofpatients;i++){
        finaldoctorsarray[i].print(originalnumberofapp);
    }
    delete []arrayofpatients;
    arrayofpatients= NULL;
    delete [] arrayofdoctors;
    arrayofdoctors= NULL;
    return 0;
}
