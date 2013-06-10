/*
@ Ankit Parekh
8 June 2013
ankitparekh8@gmail.com
*/


#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iterator>
#include<set>

using namespace std;

typedef struct path_node
{
   int first;
   int last;      
}path_node;

typedef struct customer
{
    int no_words;
    int vowels;
    int consonants;        
        
}customer;



class Scores
{
 public:
   vector<string> Persons;
   vector<string> Product;   
   vector< vector<float> > score;
   vector<path_node> path;
   vector<customer> cust;
      
   Scores(vector<string> &Pers,vector<string> &Prod)
   {
        
         Persons = Pers;
         Product = Prod;
         
         fill_customer(Persons);
         calculate_scores(Pers,Prod);
         setup_initial_path();
   }    
   
   
   void setup_initial_path()
   {
          
      
      set<int> marked;
      set<int> marked_col;
  
      while(1)
      {
           if(marked.size() == Persons.size()  ||  marked_col.size() == Product.size())
           {
                  break;                 
           }
           float high_score = -1.0;
           path_node pos;                        
           
           for(int i=0;i<score.size();i++)
           {
                  
                  if(marked.find(i) != marked.end())
                  {
  
                       continue;
                  }
                        
                  vector<float> v =score[i];
                  for(int j=0;j<v.size();j++)
                  {
                          if(marked_col.find(j) != marked_col.end())
                          {
                              continue;                      
                          }
                         if(high_score < v[j])
                         {
                              high_score = v[j];
                              pos.first = (int)i;
                              pos.last = (int)j;               
                         }                            
                  }
           }
           
           path.push_back(pos);       
           marked.insert(pos.first);
           marked_col.insert(pos.last);
           
           
          
      }
      
      
   
   }
   
   
   void calculate_scores(vector<string> Persons,vector<string> Product)
   {
       
       for(int i = 0; i < Persons.size();i++)
       {    vector <float> v;
            for(int j=0;j<Product.size();j++)
            {
                 float sc =    SS_Score(i,Product[j]);
           
                 v.push_back(sc);
          
            }
            score.push_back(v);        
               
       }      
    
   }
   
   float SS_Score(int pos,string &product)
   {
       float sc = 0.0;
       
       int p = num_words(product); 
       if(p%2 == 0)  //if even
       {
           sc = cust[pos].vowels * 1.5;                        
       }
       else
       {
           sc = cust[pos].consonants;    
       }
       if(gcd(cust[pos].no_words,p)>1)
       {
           sc = sc * 1.5;           
       }
      
       return sc;      
         
   }
   
   
   int gcd(int a, int b)
   {
      int temp;

      while(b)
      {
         temp = a % b; 
         a = b; 
         b = temp;
      }
      
      return(a);
    }
   
   void sort_matrix()
   {
         float last_total_score = 0;
         for(int time = 0 ; time < 100 ; time++)
         {
            bool any_switched = false;
            for(int n = 0; n<path.size()-1 ; n++)
            {
                int row = path[n].first; 
                int col = path[n].last;
                
                int next_row = path[n+1].first;
                int next_col = path[n+1].last;
                
                float diag_sum = score[row][col] + score[next_row][next_col];
                float anti_diag_sum = score[row][next_col] + score[next_row][col];
                
                bool diag_sum_larger = diag_sum > anti_diag_sum ; 
                
                bool switch_cols = (diag_sum_larger && (score[next_row][next_col] > score[row][col])) || (!diag_sum_larger && (score[row][next_col] >= score[next_row][col]));
                bool switch_rows = (diag_sum_larger && (score[next_row][next_col] > score[row][col])) || (!diag_sum_larger && (score[next_row][col] >  score[row][next_col]));
                               
                if (switch_cols)
                {
                    any_switched = true;
                    path[n].last = next_col;
                    path[n + 1].last =  col;
                }                    
                
                if (switch_rows)
                {
                    any_switched = true;
                    path[n].first = next_row;
                    path[n + 1].first =  row;
                }
            }//end for path
            if (last_total_score == total_score())
            {
               break;
            }
            else
            {
                last_total_score = total_score();
            }
                  
         }     //end for time
        
              
   }//end function

   float total_score()
   {
         float sum = 0;
         for(int i=0;i<path.size();i++)
         {
             sum = sum + score[path[i].first][path[i].last];        
         }     
         return sum;
   }
   
   int num_words(string s)
   {
       int words = 0;
       for(int i=0;i<s.length();i++)
       {
            if( (s.at(i)>= 'a' && s.at(i) <='z') || (s.at(i)>= 'A' && s.at(i) <='Z') )
            {
              words++;
            }                   
       }
       return words;
       
   }
   
      
   
   
   
void fill_customer(vector<string> People)
{
    for(int i=0;i<People.size();i++)
    {
         string s = People[i];
         int words=0;
         int vowels = 0;
         for(int j=0;j<s.length();j++)
         {
             if( (s.at(j)>= 'a' && s.at(j) <='z') || (s.at(j)>= 'A' && s.at(j) <='Z') )
            {
              words++;
            }
            
            switch(s.at(j))
            {
                 case 'a' :
                 case 'A' :  vowels++;
                             break; 
                             
                 case 'e' :
                 case 'E' :  vowels++;
                             break;
                             
                 case 'i' :
                 case 'I' :  vowels++;
                             break; 
                             
                 case 'o' :
                 case 'O' :  vowels++;
                             break;
                             
                 case 'u' :
                 case 'U' :  vowels++;
                             break;
                             
                 case 'y' :
                 case 'Y' :  vowels++;
                             break;             
            }    
                 
         }   
         customer c;
         c.no_words = words;
         c.vowels = vowels;
         c.consonants = words - vowels;
         cust.push_back(c);    
            
    }    
     
     
}

   
   
   
         
};







float find_max_SS(vector<string> Persons,vector<string> Product)
{
    Scores sc (Persons,Product);      
    sc.sort_matrix();
    return sc.total_score();
    //return 1.0;
}


int main (int argc, char* argv[]) 
{
   ifstream file;
   string line;
   size_t pos = 0;

   
   file.open(argv[1]);

   while (!file.eof()) 
   {
       getline(file, line);
       if (line.length() == 0)
           continue; //ignore all empty lines
       else 
       {
            string delimiter = ";";           
        string tok1,tok2;
    
    	pos = line.find(delimiter);
		tok1 = line.substr(0,pos);
		line.erase(0,pos+delimiter.length());
		tok2 = line;
		
        vector<string> Persons,Product;
		delimiter = ",";
		string token;
		
		
        while ((pos = tok1.find(delimiter)) != string::npos) 
        {
              token = tok1.substr(0, pos);
              Persons.push_back(token);
              tok1.erase(0, pos + delimiter.length());
        }
        Persons.push_back(tok1);
        
        
        while ((pos = tok2.find(delimiter)) != string::npos) 
        {
              token = tok2.substr(0, pos);
              Product.push_back(token);
              tok2.erase(0, pos + delimiter.length());
        }
        Product.push_back(tok2);
        
                
                
        cout.precision(2);        
        cout << fixed <<find_max_SS(Persons,Product) << endl;
           
       }
    }
   
}



