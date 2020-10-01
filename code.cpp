#include <iostream>
#include<stdlib.h>

using namespace std;

const int MAX=10;
//creating class dictionary
class dictionary;
class node
{
      string key,value;
      node *next;
public:
      //creating freind class dictionary
      friend class dictionary;
      node()//constructor
      {
            next=NULL;
      }
      node(string key,string value)
      {
            this->key=key;//this refers to current object
            this->value=value;
            next=NULL;
      }
};
//Defining class dictionary
class dictionary
{
      node *head[MAX];
public:
      dictionary()
{
            for(int i=0;i<MAX;i++)
                  head[i]=NULL;
}
      int hash(string word,int MAX);//hashing

      /*The program does five major functions:-

       1)Insertion( word and meaning)
       2)Deletion( deleting the word)
       3)Searching/Finding
       4)Listing out
       5)Updation
      */
      void insert(string,string);
      void find(string word);
      bool deleteWord(string word);
      void disp();
};

//friend function
int dictionary::hash(string word,int MAX)
{
      int sum=0;
      for(int i=0;i<word.length();i++)
      {
            sum=sum+word[i];
      }
        sum%=MAX;
        if (sum<0)
            sum+=MAX;
        return sum;
}


//finding for the string
void dictionary::find(string word)
{
      int index=hash(word,MAX);
      int flag=0;
      node *start=head[index];
      while(start!=NULL)
      {

            if(start->key==word)
            {
                  flag=1;
                  break;
            }
            start=start->next;
      }
      if(flag==1)
            {cout<<"Word Is  present.";
            cout<<"\n"<<word<<"\n================"<<"\n"<<start->value<<"\n";}
      else
            cout<<"Word Is not present.\n";
}

//Insertion
void dictionary::insert(string word,string meaning)
{   char y;
    string lm;
    int index=hash(word,MAX);
    node *start=head[index];
      //creating a new node for the word and meaning
      node *p=new node(word,meaning);
      while(start!=NULL)
      { if(start->key==word)
              {
                  cout<<"word is already present!"<<endl;
                  cout<<"would you like to update?(y/n):"<<endl;
                  cin>>y;
                  if(y=='y')
                    {
                         cout<<"please enter the new meaning: "<<endl;
                         cin.ignore();
                         getline(cin,lm);
                         start->value=lm;
                         break;
                    }
                    else
                    {
                        break;
                    }

              }
              else
              {
                  continue;
              }


              }



      if(head[index]==NULL)
      {
            head[index]=p;
      }
      else
      {
            node *start=head[index];
            while(start->next!=NULL)
            {

                  start=start->next;

            start->next=p;
      }

      cout<<endl<<lm<<" is set as the new meaning for "<<word;
}

}


//Deletion
bool dictionary::deleteWord(string word)
{
      int index=hash(word,MAX);
      node *tmp=head[index];
      node *par=head[index];
      if(tmp==NULL) //if no word is present at that index it
      {
            return false;
      }
      if(tmp->key==word && tmp->next==NULL)//only one word is present
      {
            head[index]=NULL;
            delete tmp;
            return true;
      }
      //tmp=tmp->next;
      while(tmp->key!=word && tmp->next!=NULL)
      {
            par=tmp;
            tmp=tmp->next;
      }
      if(tmp->key==word&&tmp->next!=NULL)
      {
          if(par->key==tmp->key)
          {
              head[index]=tmp->next;
          }
          else
          {
            par->next=tmp->next;
            tmp->next=NULL;
          }
            delete tmp;
            return true;
      }
      else //delete at end
      {
            par->next=NULL;
            tmp->next=NULL;
            delete tmp;
            return true;
      }
      return false;
}

void dictionary:: disp()
{
      cout<<"\nIndex\t Key\t Value";
      for(int i=0;i<100;i++)
      {
            node *start=head[i];
            if(start==NULL)
                  cout<<"\n";
            while(start!=NULL)
            {
                  cout<<"\n:"<<i<<"\t"<<start->key <<"\t "<<start->value;
                  start=start->next;
            }
      }
}



int main() {
      dictionary o1;
      int choice;
      string word;
      string meaning;
      system("COLOR 74");
      do {
            cout<<"\nO(1) Dictionary\n"
                        <<"1-Insert a Word the dictionary\n"
                        <<"2-Find Word in the dictionary\n"
                        <<"3-Delete Word from the dictionary\n"
                        <<"4-Display entire dictionary\n"
                        <<"5-EXIT\n"
                        <<"Enter Your Choice :";
            cin>>choice;
            switch(choice)
            {
            case 1:
                  cout<<"Enter The Word: ";
                  cin>>word;
                  cin.ignore();
                  cout<<"Enter The Meaning: ";
                  getline(cin,meaning);
                  o1.insert(word,meaning);

                  break;
            case 2:
                  cout<<"Enter Word to Search For: ";
                  cin>>word;
                  o1.find(word);

                  break;
            case 3:
                  cout<<"Enter Word to Delete For : ";
                  cin>>word;
                  if(o1.deleteWord(word))
                        cout<<" Word is deleted.";
                  else
                  {
                        cout<<"\nFailed to delete "<<word;
                  }
                  break;

            case 4:
                  cout<<"the O(1) Dictionary";
                  o1.disp();
                  break;
            case 5:
                cout<<"Thank you for using the O(1) Dictionary";
                break;
            default:
                  cout<<"\nWrong Choice.";
                  break;
            }

      }while(choice!=5);

      return 0;
}







