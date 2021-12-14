#include <iostream>
#include <stack>
#include<bits/stdc++.h>
using namespace std;
void PrintStackR(stack<char> *s){
    if (s->empty())
        return;
    char x = s->top();
    s->pop();
    PrintStackR(s);
    cout<<x;
    s->push(x);
}

void PrintStack(stack<char> *s){
    if (s->empty())
        return;
    char x = s->top();
    s->pop();
    cout<<x;
    PrintStack(s);
    s->push(x);
}
 
class text_editor{
    public:
    stack<char> *left;
    stack<char> *right;
    stack<char> *redof;
    text_editor(){
        left=new stack<char>();
        right=new stack<char>();
        redof=new stack<char>();
    }
    void insert(string input){
        for(int i=0;i<input.size();i++){
            left->push(input[i]);
        }
    }
    void backspace(){
        if(left->empty()){
            return;
        }
        else{
            left->pop();
        }
    }
    void delet(){
        if(right->empty()){
            return;
        }
        else{
            right->pop();
        }
    }
    void undo(){
        redof->push(left->top());
        left->pop();
    }
    void redo(){
        left->push(redof->top());
        redof->pop();
    }
    void move_left(int amount){
        while(!left->empty() && amount>0){
            right->push(left->top());
            left->pop();
            amount--;
        }
    }
    void move_right(int amount){
        if(right->empty()){
            while(amount--){
                left->push(' ');
            }    
        }
        else{
            while(!right->empty() && amount>0){
                if(right->empty()){
                    left->push(' ');
                }
                left->push(right->top());
                right->pop();
                amount--;
            }
        }
    }
    void read(){
        PrintStackR(left);
        PrintStack(right); 
}
};
int main(){
    text_editor content;
    cout<<"----MENU----"<<endl;
    cout<<"1. Write Text \n2. Read Text \n3. Remove Text \n4. Delete Text \n5. Move cursor Left \n6. Move cursor Right \n7. Undo \n8. Redo \n9. Exit"<<endl;
    int a;
    cout<<"Enter your Choice: ";
    cin>>a;
    while(a<=9){
        switch(a){
            case 1:{
                string s;
                cout<<"Enter text to write: ";
                cin.ignore();
                getline(cin,s);
                content.insert(s);
                cout<<"Text Added!"<<endl;
                break;
            }
            case 2:{
                cout<<"Your text is as follows-"<<endl;
                content.read();
                cout<<endl;
                break;
            }
            case 3:{
                int d;
                cin.ignore();
                cout<<"Enter number of characters to remove: ";
                cin>>d;
                while(d--){
                    content.backspace();
                }
                cout<<"Text Deleted!"<<endl;
                break;
            }
            case 4:{
                int d;
                cin.ignore();
                cout<<"Enter number of characters to delete: ";
                cin>>d;
                while(d--){
                    content.delet();
                }
                cout<<"Text Deleted!"<<endl;
                break;
            }
            case 5:{
                int p;
                cin.ignore();
                cout<<"Enter number of positions to shift cursor left by: ";
                cin>>p;
                content.move_left(p);
                cout<<"Cursor shifted!"<<endl;
                break;
            }
            case 6:{
                int p;
                cin.ignore();
                cout<<"Enter number of positions to shift cursor right by: ";
                cin>>p;
                content.move_right(p);
                cout<<"Cursor shifted!"<<endl;
                break;
            }
            case 7:{
                content.undo();
                cout<<"Undo Done!"<<endl;
                break;
            }
            case 8:{
                content.redo();
                cout<<"Redo Done!"<<endl;
                break;
            }
            case 9:{
                cout<<"EXITING"<<endl;
                cout<<"\n\n-----THANK YOU FOR USING TEXT-IT-UP-----"<<endl;
                break;
            }
            default:{
                cout<<"Invalid Choice"<<endl;
                break;
            }
        }
        if(a==9){
            break;
        }
        else{
            cout<<"Enter your Choice: ";
            cin>>a;
        }
    }
    return 0;
}
