#include <iostream>
using namespace std;

template <typename T>
class Node{
    private:
        T data;
        Node <T>* next;
        Node <T>* prev;

    public:
        Node <T>(){
            next = prev = nullptr;
        }

        Node <T>(T data){
            this->data = data;
            next = prev= nullptr;
        }

        T& get_data(){
            return data;
        }

        const T& get_data() const{
            return data;
        }

        void set_data(T data){
            this->data = data;
        }

        Node <T>* get_next() const{
            return next;
        }

        void set_next(Node <T>* next){
            this->next = next;
        }

        Node <T>* get_prev() const{
            return prev;
        }

        void set_prev(Node <T>* prev){
            this->prev = prev;
        }

};



template <typename T>
class List{
    private:
        Node <T>* head;
        Node <T>* tail;
        int length;

    public:
        List <T> (){
            length = 0;
            head = tail = nullptr;
        }

        void push_back(T data){
            Node <T>* node = new Node <T> (data);

            if (head == NULL){
                node->set_next(nullptr);
                node->set_prev(nullptr);
                head = tail = node;
            }
            else {
                node->set_next(nullptr);
                node->set_prev(tail);
                tail->set_next(node);
                tail = node;
            }
            length++;
        }

        void push_front(T data){
            Node <T>* node = new Node <T>(data);

            if (head == NULL){
                node->set_next(nullptr);
                node->set_prev(nullptr);
                head = tail = node;
            }
            else {
                node->set_next(head);
                node->set_prev(nullptr);
                head->set_prev(node);
                head = node;
            }

            length++;
        }

        void pop_back(){
            if (head == nullptr){
                cout<<"NULL"<<endl;
                return;
            }

            if (head == tail){
                delete head;
                head = tail = nullptr;
                length--;
                return;
            }

            Node <T>* temp = tail;

            tail = tail->get_prev();
            tail->set_next(nullptr);

            delete temp;

            length--;
        }


        void pop_front(){
            if (head == nullptr){
                cout<<"NULL"<<endl;
                return;
            }

            if (head == tail){
                delete head;
                head =  tail = nullptr;
                length--;
                return;
            }

            Node <T>* temp = head;

            head = head->get_next();
            head->set_prev(nullptr);
            delete temp;

            length--;
        }

        int size(){
            return length;
        }

        T& operator [](int index){
            if (index < 0 || index >= length){
                throw out_of_range("Index out of range");
            }

            Node <T>* temp = head;

            for (int i=0; i<index; i++){
                temp = temp->get_next();
            }

            return temp->get_data();
        }

        void traverse(){
            if (head == nullptr){
                cout<<"NULL"<<endl;
                return;
            }

            Node <T>* temp = head;

            while (temp != nullptr){
                cout<<temp->get_data()<<"\t";
                temp = temp->get_next();
            }
            cout<<"NULL"<<endl;
        }

};


int main(){
    
}