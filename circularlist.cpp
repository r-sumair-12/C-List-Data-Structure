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
            Node <T>* node = new Node <T> (data);

            if (head == nullptr){
                head = tail = node;
                tail->set_next(head);                
            }
            else {
                node->set_next(head);
                tail->set_next(node);
                tail = node;
            }
            length++;
        }

        void push_front(T data){
            Node <T>* node = new Node <T> (data);

            if (head == nullptr){
                head = tail = node;
                tail->set_next(head);
            }
            else {
                node->set_next(head);
                tail->set_next(node);
                head = node;
            }
            length++;
        }

        T pop_back(){
            if (head == nullptr){
                cout<<"NULL"<<endl;
                return NULL;
            }

            if (head == tail){
                T poped = head->get_data();
                delete head;
                head = tail = nullptr;
                length--;
                return poped;
            }

            Node <T>* temp = tail;

            do {
                temp = temp->get_next();
            }
            while (temp->get_next() != tail);

            T poped = tail->get_data();

            delete tail;
            temp->set_next(head);
            tail = temp;
            length--;

            return poped;
        }


        T pop_front(){
            if (head == nullptr){
                cout<<"NULL"<<endl;
                return NULL;
            }

            if (head == tail){
                T poped = head->get_data();
                delete head;
                head = tail = nullptr;
                length--;
                return poped;
            }

            Node <T>* temp = head;

            T poped = temp->get_data();

            head = head->get_next();
            tail->set_next(head);
            delete temp;

            length--;
            return poped;
        }

        int size(){
            return length;
        }

        bool empty(){
            return head == nullptr;
        }

        void sort(){
            if (head == nullptr){
                return;
            }
            bool swapped;

            do{
                swapped = false;
                Node <T>* temp = head;
                

                do {
                    Node <T>* next = temp->get_next();
                    if (temp->get_data() > next->get_data()){
                        T tmp = temp->get_data();
                        temp->set_data(next->get_data());
                        next->set_data(tmp);
                        swapped = true;
                    }

                    temp = temp->get_next();
                    next = temp->get_next();
                }
                while (temp != tail);
            } while (swapped);
        }

        void traverse(){
            if (head == nullptr){
                cout<<"NULL"<<endl;
                return;
            }

            Node <T>* temp = head;

            do {
                cout<<temp->get_data()<<"->";
                temp = temp->get_next();
            }
            while (temp != head);
        }
};


int main(){
    
}