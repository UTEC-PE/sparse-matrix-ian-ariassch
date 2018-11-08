#ifndef MATRIX_H
#define MATRIX_H

#include "node.h"

using namespace std;

template <typename T>
class Matrix {
    private:
        Node<T>* hRows;
        Node<T>* hColumns;
        int columns;
        int rows;

    public:
        Matrix(){};
        Matrix(int sizeX, int sizeY)
        {

            hRows = new Node<T>;
            hColumns = new Node<T>;
            columns=sizeX;
            rows=sizeY;
            hRows->data=0;
            hRows->x=0;
            hRows->y=1;
            hColumns->data=0;
            hColumns->x=1;
            hColumns->y=0;
            auto *tempn = hColumns;
            auto *tempd = hRows;
            for(int x=1; x<=sizeX; x++)
            {
                auto *temp = new Node<T>;
                tempn->next=temp;
                temp->x=x;
                temp->y=0;
                temp->data=x;
                tempn = temp;
            }
            for(int y=1; y<=sizeY; y++)
            {
                auto *temp = new Node<T>;
                tempd->down=temp;
                temp->x=0;
                temp->y=y;
                temp->data=y;
                tempd = temp;
            }

        }

        void set(int x, int y, T data)
        {

            if(x==0 or y==0){
                cout << "IllegalIndexPosition" << endl;
                throw;
            }
            if(x>columns or y>rows)
            {
                cout<< "OutOfRange"<<endl;
                throw;
            }
            else
            {

                auto *tempX = hColumns;
                auto *tempY = hRows;
                auto *nodo = new Node<T>;
                nodo->x = x;
                nodo->y = y;
                nodo->data = data;
                for(int xi=0; xi<=columns; xi++)
                {
                    if(tempX->x==nodo->x)
                    {
                        if(tempX->down==NULL)
                        {
                            tempX->down=nodo;
                        }

                        if(tempX->down->y>nodo->y)
                        {
                            nodo->down=tempX->down;
                            tempX->down=nodo;
                        }
                        else if(tempX->down->y<nodo->y)
                        {
                            tempX->down->down=nodo;
                        }

                        break;
                    }
                    if(tempX->next!=NULL)
                    {
                    tempX = tempX->next;
                    }
                }
                for(int yi=0; yi<=rows; yi++)
                {
                    if(tempY->y==nodo->y)
                    {
                        if(tempY->next==NULL)
                        {
                            tempY->next=nodo;
                        }

                        if(tempY->next->x>nodo->x)
                        {
                            nodo->next=tempY->next;
                            tempY->next=nodo;
                        }
                        else if(tempY->next->y<nodo->y)
                        {
                            tempY->next->next=nodo;
                        }

                        break;
                    }
                    if(tempY->down!=NULL)
                    {
                        tempY = tempY->down;
                    }
                }
                cout<<"Created node in"<<" "<<nodo->x<<" "<<nodo->y;
            }

        };
        T operator()(int x, int y)
        {
            auto *temp = hColumns;
         
            while(temp->x != x and temp->next != NULL)
            {
                temp=temp->next;
                while(temp->y != y and temp->down != NULL)
                {
                    temp=temp->down;
                }
            }
            return temp->data;
        };
        Matrix<T> operator*(Matrix<T> other){};
        Matrix<T> operator*(T scalar){};
        Matrix<T> operator+(Matrix<T> other){};
        Matrix<T> operator-(Matrix<T> other){};
        Matrix<T> transposed(){};
        Matrix<T> operator=(Matrix<T> other){};

        ~Matrix(){};
};

#endif
