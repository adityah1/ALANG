#include<time.h>
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <sstream>
#include "analyzer.hpp"
#include "createfile.hpp"
#include "convertor.hpp"

using namespace std;


int main()
{
    int count=0;
    int n;
    string dir,title,img;
    Equip_Necessary b;
    cout<<" \n *** ALANG LEXIVERTER ***\n";
    string path;
    count+=10;
    cout<<"Checking for Input.alg\n";
    //system("pause");
    system("notepad.exe input.alg");
    cout<<"Reading default file: input.alg\n";
    cout<<"\nEnter Website Title: ";
    cin>>title;
    count+=10;
    cout<<"\nWhere do you Want to Create the Website Directory? (Eg: C:\\Test) :  ";
    cin>>dir;
    b.create(dir);
    count+=30;
    ofstream file;
    file.open("Index.html", ios:: out);
    string str,str1,str2,str3;
    count+=20;
    provide_htmlcss a;

    /*The Following code relates to the css style append fn alone*/
    string style="/*\n\tStyle.css Generated by ALANG \n*/\n\ncredits{ \n\ttext-align:center;\n}\ntable{\n\tborder:1px solid #000;\n}\ntd,th{\n\tborder:1px solid #000;\n\tpadding:10px;\n}\nimg{max-width:100%}\n";      //style string passes all the code
    a.File_append(style);

    str1=a.header(title);
    str2=a.footer();
    count+=10;
    string text=getinputandsend(path);
    cout<<"\n\t\tPlease wait, your website is being generated.\n";
    count+=20;
    progbar(count);
    cout<<"Input : ---- \n"<<text<<"\n-----\n";
    string s="";
    Tags t;
    int i=0;
    clock_t ti;
    ti=clock();
    while(i<text.size()-2){
            s+=t.start_s(text,i);
    }
    ti=clock()-ti;
    float ft=(float)((float)ti/CLOCKS_PER_SEC);
    cout<<"Time taken to convert is:"<<ft<<endl;
    str=str1+s+str2;                                     //+str3 - Body Contents
    file<<str;
    move_file(dir, file);
    dir+="\\Index.html";
    system("pause");
    system((dir).c_str());                                  //Used for Opening the File Through cmd Prompt
    file.close();
    b.remove_files();
}
