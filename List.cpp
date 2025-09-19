#include <iostream>
using namespace std;

template <typename T>
class Node{
    private:
        T data;
        Node <T>* next;

    public:
        Node <T>(){
            next = nullptr;
        }

        Node <T>(T data){
            this->data = data;
            next = nullptr;
        }

        T get_data() const {
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
            Node <T>* node = new Node <T>(data);

            if (head == nullptr){
                node->set_next(nullptr);
                head = tail = node;
            }
            else {
                node->set_next(nullptr);
                tail->set_next(node);
                tail = node;
            }
            length++;
        }

        void push_front(T data){
            Node <T>* node = new Node <T> (data);

            if (head == nullptr){
                node->set_next(nullptr);
                head = tail = node;
            }
            else {
                node->set_next(head);
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

            Node <T>* temp = head;

            while (temp->get_next() != tail){
                temp = temp->get_next();
            }

            delete tail;
            tail = temp;
            tail->set_next(nullptr);
            length--;
        }


        void pop_front(){
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

            Node <T>* temp = head;

            head = head->get_next();
            delete temp;
            length--;
        }

        int size(){
            return length;
        }

        void traverse(){
            if (head == nullptr){
                cout<<"NULL"<<endl;
                return;
            }

            Node <T>* temp = head;

            while (temp != nullptr){
                cout<<temp->get_data()<<"->";
                temp = temp->get_next();
            }
            cout<<"NULL"<<endl;
        }
};


int main(){
    
}