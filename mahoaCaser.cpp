#include <iostream>
#include <string.h>

using namespace std;
void encypt(char* text, int shift){
    int n=strlen(text);
    for(int i=0;i<n;i++){
        if(text[i]>='A'&& text[i]<='Z'){
            int x=text[i]+shift%26;
            text[i]=65+(x-65)%26;
        }else{
            int x=text[i]+shift%26;
            text[i]=97+(x-97)%26;
        }
    }
}
void decypt(char* text, int shift){
    int n=strlen(text);
    for(int i=0;i<n;i++){
        if(text[i]>='A'&& text[i]<='Z'){
            int x=text[i]+26-shift%26;
            text[i]=65+(x-65)%26;
        }else{
            int x=text[i]+26-shift%26;
            text[i]=97+(x-97)%26;
        }
    }
}
int main(){
    int n,shift;
    cin>>n>>shift;
    char* text = new char[n+1];
    for(int i=0;i<n;i++){
        cin>>text[i];
    }
    text[n]='\0';
    encypt(text,shift);
    puts(text);
    decypt(text,shift);
    puts(text);
    return 0;
}