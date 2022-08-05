/*
    Pontificia Universidad Javeriana

    Estructuras de datos

    Emma Juliana Gachancipa Castelblanco

    Tarea 1

    Compilar:
        g++ -std=c++11 main_emma_tarea_1.cpp -o main_emma_tarea_1

    Ejecutar:
        ./main_emma_tarea_1
*/

#include <iostream>
#include <cstdlib>

#include <vector>
#include <deque>
#include <list>

void print_vector(std::vector<int> arr, char it_type){
    /*
        it_type:
            'N' -> Normal
            'R' -> Reverse
    */

    // ITERADOR NORMAL
    if (it_type == 'N')
    {
        std::cout << std::endl << "Normal iterator:"<< std::endl;

        // Declarar iterador normal
        std::vector<int>::iterator it_vector;

        // Recorrer elementos e imprimir
        for (it_vector=arr.begin(); it_vector!=arr.end(); it_vector++)
            std::cout << *it_vector << " ";
        std::cout << std::endl << std::endl;
    }
    // ITERATOR EN REVERSA
    else if (it_type == 'R')
    {
        std::cout << "Reverse iterator:" << std::endl;
        
        // Declarar iterador reversa
        std::vector<int>::reverse_iterator r_it_vector;

        // Recorrer elementos e imprimir
        for (r_it_vector=arr.rbegin(); r_it_vector!=arr.rend(); r_it_vector++)
            std::cout << *r_it_vector << " ";
        std::cout << std::endl << std::endl;
    }
}

void print_deque(std::deque<int> dcola, char it_type){
    /*
        it_type:
            'N' -> Normal
            'R' -> Reverse
    */

    // ITERADOR NORMAL
    if (it_type == 'N')
    {
        std::cout << std::endl << "Normal iterator:"<< std::endl;

        // Declarar iterador normal
        std::deque<int>::iterator it_dcola;

        for (it_dcola=dcola.begin(); it_dcola!=dcola.end(); it_dcola++)
            std::cout << *it_dcola << " ";
        std::cout << std::endl << std::endl;
    }
    // ITERATOR EN REVERSA
    else if (it_type == 'R')
    {
        std::cout << "Reverse iterator:" << std::endl;
    
        // Declarar iterador reversa
        std::deque<int>::reverse_iterator r_it_dcola;

        for (r_it_dcola=dcola.rbegin(); r_it_dcola!=dcola.rend(); r_it_dcola++)
            std::cout << *r_it_dcola << " ";
        std::cout << std::endl << std::endl;
    }
}


void print_list(std::list<int> lista, char it_type){
    /*
        it_type:
            'N' -> Normal
            'R' -> Reverse
    */

    // ITERADOR NORMAL
    if (it_type == 'N')
    {
        std::cout << std::endl << "Normal iterator:"<< std::endl;

        // Declarar iterador normal
        std::list<int>::iterator it_lista;

        for (it_lista=lista.begin(); it_lista!=lista.end(); it_lista++)
            std::cout << *it_lista << " ";
        std::cout << std::endl << std::endl;
    }
    // ITERATOR EN REVERSA
    else if (it_type == 'R')
    {
        std::cout << "Reverse iterator:" << std::endl;
    
        // Declarar iterador reversa
        std::list<int>::reverse_iterator r_it_lista;

        for (r_it_lista=lista.rbegin(); r_it_lista!=lista.rend(); r_it_lista++)
            std::cout << *r_it_lista << " ";
        std::cout << std::endl << std::endl;
    }
}

int main(){
    int i;

    // _______________VECTOR_______________

    std::cout << std::endl << "_______________VECTOR_______________" << std::endl;

    // Declarar vector
    std::vector<int> arr;

    // Insertar elementos en el vector
    for (i=0; i<25; i++)
        arr.push_back(rand() % 100);
    
    // Validar el tamaño del vector y sus elementos
    std::cout << std::endl << "Size: " << arr.size() << std::endl;

    print_vector(arr, 'N');
    print_vector(arr, 'R');

    std::cout << std::endl << "- Insert value at index 18: " << std::endl;

    // Insertar valor en la pos. 18
    arr.insert(arr.begin() + 18, 101);

    print_vector(arr, 'N');

    std::cout << std::endl << "- Delete value at index 10: " << std::endl;

    // Eliminar valor en la pos. 10
    arr.erase(arr.begin() + 10);

    print_vector(arr, 'N');

    std::cout << std::endl << "- Delete value at index 5: " << std::endl;

    // Eliminar valor en la pos. 5
    arr.erase(arr.begin() + 5);

    print_vector(arr, 'N');

    // _______________DCOLA_Y_LISTA_______________
    
    // Declarar cola y lista
    std::deque<int> dcola;
    std::list<int> lista;

    // Insertar elementos en la cola y la lista
    for (i=0; i<15; i++) {
        dcola.push_back(rand() % 100);
        dcola.push_front(rand() % 100);

        lista.push_back(rand() % 100);
        lista.push_front(rand() % 100);
    }

    
    // _______________DCOLA_______________
    
    std::cout << std::endl << "_______________DCOLA_______________" << std::endl;

    // Validar el tamaño de la cola y sus elementos
    std::cout << std::endl << "Size: " << dcola.size() << std::endl;

    print_deque(dcola, 'N');
    print_deque(dcola, 'R');

    std::cout << std::endl << "- Insert value at index 18: " << std::endl;

    // Insertar valor en la pos. 18

    dcola.insert(dcola.begin() + 18, 101);

    print_deque(dcola, 'N');

    std::cout << std::endl << "- Delete value at index 10: " << std::endl;

    // Eliminar valor en la pos. 10
    dcola.erase(dcola.begin() + 10);

    print_deque(dcola, 'N');

    std::cout << std::endl << "- Delete value at index 5: " << std::endl;

    // Eliminar valor en la pos. 5
    dcola.erase(dcola.begin() + 5);

    print_deque(dcola, 'N');
    
    
    // _______________LISTA_______________

    std::cout << std::endl << "_______________LISTA_______________" << std::endl;

    // Validar el tamaño del vector y sus elementos
    std::cout << std::endl << "Size: " << lista.size() << std::endl;

    print_list(lista, 'N');
    print_list(lista, 'R');

    // Declarar iterador normal
    std::list<int>::iterator it_lista = lista.begin();

    // Insertar valor en la pos. 18
    std::cout << std::endl << "- Insert value at index 18: " << std::endl;
    advance(it_lista, 18);
    lista.insert(it_lista , 101);

    print_list(lista, 'N');

    std::cout << std::endl << "- Delete value at index 10: " << std::endl;
    
    // Inicializar iterador al inicio de la lista
    it_lista = lista.begin();

    // Eliminar valor en la pos. 10
    advance(it_lista, 10);
    lista.erase(it_lista);

    print_list(lista, 'N');

    std::cout << std::endl << "- Delete value at index 5: " << std::endl;

    // Inicializar iterador al inicio de la lista
    it_lista = lista.begin();

    // Eliminar valor en la pos. 5
    advance(it_lista, 5);
    lista.erase(it_lista);

    print_list(lista, 'N');
}
