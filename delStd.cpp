#include"student.h"

void delStu()
{
    fstream fobj, fobj2;
    fobj.open("data\\storage.dat", ios::binary | ios::out | ios::in);
    fobj2.open("data\\temp.dat", ios::binary | ios::out);
    int rollno, found = 0;
    cout << "enter student roll no.";
    cin >> rollno;
    student temp;
    while (fobj.read(reinterpret_cast<char *>(&temp), sizeof(student)))
    {
        if (temp.rollno != rollno)
        {
            fobj2.write(reinterpret_cast<char *>(&temp), sizeof(student));
        }
        else
            found=1;
    }
    fobj.close();
    fobj2.close();
    remove("data\\storage.dat");
    rename("data\\temp.dat","data\\storage.dat");
    if (!found)
    {
        cout << "Student Record Doesn't exist !!" << endl;
    }
    else
    {
        cout << "Student Record deleted Succesfully!!" << endl;
    }
}