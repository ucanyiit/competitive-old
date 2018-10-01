// Write your Student class here

class Student { 
    // Access specifier 
    public: 
    
    int scores[5];
    // Data Members 
    string geekname; 
  
    // Member Functions() 
    void input() { 
        int t=0;
        while(t++<5) cin>>scores[t];
    } 
    
    int calculateTotalScore(){
        int t=0, s=0;;
        while(t++<5) s+=scores[t];
        return s;
    }
}; 