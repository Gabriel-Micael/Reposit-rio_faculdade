#include <iostream>

using namespace std;

typedef struct no_{
    int chave;
    int valor;
    struct no_ * prox;
}no;

no* inicia_lista(){
    no* ptlista = new no;
    ptlista->chave = 0;
    ptlista->valor = 0;
    ptlista->prox = NULL;
    return ptlista;
}

void encerra_lista(no* ptlista){
    no* ant;
    for(no* pont = ptlista->prox; pont != NULL; ){
        ant = pont;
        pont = pont->prox;
        delete (pont);
    }
}

no* busca_enc(no* ptlista, int chave){
    no* aux = ptlista->prox;
    no* ant = ptlista;
    for(; aux != NULL && aux->chave != chave; aux = aux->prox, ant = ant->prox){
    }
    if(aux != NULL){
        return ant;
    }else{
        return NULL;
    }
}

no* insercao_enc(no* ptlista, int chave, int valor){
    no* aux = ptlista;
    for(; aux->prox != NULL; aux = aux->prox){
    }
    aux->prox = new no;
    aux->prox->chave = chave;
    aux->prox->valor = valor;
    aux->prox->prox = NULL;
    return aux;
}

no* remocao_enc(no* ptlista, int chave){
    no* aux;
    no* indice = busca_enc(ptlista, chave);
    if(indice != NULL){
        aux = indice->prox;
        return aux;
        indice->prox == indice->prox->prox;
    }else{
        return NULL;
    }
}

void mostrar_enc(no* ptlista){
    for(no* aux = ptlista->prox; aux != NULL; aux = aux->prox){
        cout << "chave: " << aux->chave << "    valor: " << aux->valor << endl;
    }
}

int main(){
    no* ptlista = inicia_lista();
    no* remove;
    int opc, chave, valor;
    do{
        cout << "------------------------------------------------" << endl << "0 - Sair" << endl << "1 - Buscar" <<  endl << "2 - Remover" << endl << "3 - Inserir" << endl << "4 - Mostrar" 
        << endl << "------------------------------------------------" << endl << "Escolha uma opção: ";
        cin >> opc;
        switch(opc){
            case 0:
            cout << endl << "Programa encerrado!" << endl;
                break;
            case 1:
                cout << "Digite a chave a procurar: ";
                cin >> chave;
                if(busca_enc(ptlista, chave)!=NULL){
                    cout << endl << "Elemento encontrado!" << endl;
                }else{
                    cout << endl <<"Elemento não encontrado!"<< endl;
                }
                break;
            case 2:
                cout << "Digite a chave a remover: ";
                cin >> chave;
                remove = remocao_enc(ptlista, chave);
                if(remove != NULL){
                    cout << endl << "Elemento encontrado e removido" << endl;
                    delete(remove);
                }else{
                    cout << endl << "Elemento não encontrado" << endl;
                }
                break;
            case 3:
                cout << endl << "Digite a chave a inserir: ";
                cin >> chave;
                cout << endl << "Agora o valor a inserir: ";
                cin >> valor;
                insercao_enc(ptlista, chave, valor);
                break;
            case 4:
                cout << endl << "Lista Encadeada:" << endl;
                mostrar_enc(ptlista);
                break;
            default:
                cout << endl << "Digite apenas '0', '1', '2', '3' ou '4'" << endl;
                break;
        }
    }while(opc != 0);
    encerra_lista(ptlista);
}