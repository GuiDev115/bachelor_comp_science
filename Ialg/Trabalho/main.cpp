#include <iostream>
#include <cstdlib>

using namespace std;

struct rodovia{
    int id;
    string nome;
    float extensao;
    int ano;
    string descricao;
    bool flag;
};

void merge(rodovia *arr, int low, int high, int mid)
{
    int i, j, k;
    rodovia c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i].nome <  (arr[j].nome)) {
            c[k].nome = arr[i].nome;
            c[k].extensao = arr[i].extensao;
            c[k].ano = arr[i].ano;
            c[k].descricao = arr[i].descricao;
            k++;
            i++;
        }
        else  {
            c[k].nome = arr[j].nome;
            c[k].extensao = arr[j].extensao;
            c[k].ano = arr[j].ano;
            c[k].descricao = arr[j].descricao;
            k++;
            j++;
        }
    }
    while (i <= mid) {
        c[k].nome = arr[i].nome;
        c[k].extensao = arr[i].extensao;
        c[k].ano = arr[i].ano;
        c[k].descricao = arr[i].descricao;
        k++;
        i++;
    }
    while (j <= high) {
        c[k].nome = arr[j].nome;
        c[k].extensao = arr[j].extensao;
        c[k].ano = arr[j].ano;
        c[k].descricao = arr[j].descricao;
        k++;
        j++;
    }
    for (i = low; i < k; i++)  {
        arr[i].nome = c[i].nome;
        arr[i].extensao = c[i].extensao;
        arr[i].ano = c[i].ano;
        arr[i].descricao = c[i].descricao;

    }
}

void merge_sort(rodovia *arr, int low, int high)
{
    int mid;
    if (low < high){
        mid=(low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,high,mid);
    }
}

rodovia *copia_vetor(rodovia *add, rodovia *vetor,int tam){ 

    int k;

	for(k = 0;k < tam;k++){
		add[k].nome = vetor[k].nome;
		add[k].extensao = vetor[k].extensao;
		add[k].ano = vetor[k].ano;
		add[k].descricao = vetor[k].descricao;
		add[k].flag = vetor[k].flag;
	}

    return add;
}

rodovia *add_vetor(int &v_inicial, rodovia *vetor){

	rodovia *add = new rodovia[v_inicial * 20/100 + v_inicial ]; //expanção dinamica do tamnaho do vetor
	copia_vetor(add,vetor,v_inicial);
	v_inicial = v_inicial + v_inicial * 0.2;

	return add;
}

void alterar (int alt, rodovia *pista){

    cout << " | O novo nome da rodovia referida: ";
    cin.ignore();
    getline(cin, pista[alt].nome);

    cout << " | Sua Extensao total: ";
    cin >> pista[alt].extensao;

    cout << " | Novo Ano de Inauguracao: ";
    cin.ignore();
    cin >> pista[alt].ano;

    cout << " | Descricao nova da rodovia: ";
    cin.ignore();
    getline(cin, pista[alt].descricao);
}

int main(){

    int saida, i, opcao = 10, vetor = 0, aux = -1, excluir;
    int v_inicial = 5, id_alterar; // Vetor inicial que pede na imenta do trabalho que é 5.

    cout << " ____________________________________________________________________________________________________________" << endl;
    cout << "|__________ Seja Bem Vindo ao Registrador 2.0 de Rodovias UFLA !!!! - Feito por: Guilherme Fabricio _________|" << endl;
    cout << "|____________________________________________________________________________________________________________|" << endl << endl;
    cout << "Comecaremos inserindo o primeiro dado do nosso registro, por padrao do inicio do programa." << endl << endl << " 1 - Aperte para Continuar o registro" << endl << "Ou - Aperta Qualquer digito para Sair";
    cout << endl << endl;
    cin >> saida;

    rodovia *pista = new rodovia[v_inicial];

    switch(saida){
        case 1: {

            cout << "O nome da rodovia referida: ";
            cin.ignore();
            getline(cin, pista[vetor].nome);

            cout << "Sua Extensao total (ja em KM): ";
            cin >> pista[vetor].extensao;

            cout << "Ano de sua inauguracao: ";
            cin >> pista[vetor].ano;

            cout << "Descricao detalhada da rodovia: ";
            cin.ignore();
            getline(cin, pista[vetor].descricao);

            pista[vetor].flag = true;

            vetor++;
            aux++;

            cout << endl;

            do{
            
            if(opcao == 10){
            cout << " ____________________________________________________________" << endl;
            cout << "|________ Bem vindo ao Menu Principal do Programa!!! ________|" << endl;
            cout << "|____________________________________________________________|" << endl << endl;
            opcao++;
            }

            else{
                cout << " ------------------------------------------------------------------- " << endl;
                cout << "  Por favor, Insira um digito correspodente dentre as opcoes abaixo"  << endl;
                cout << " ------------------------------------------------------------------- " << endl << endl;
                cout << " 1 - Incluir " << endl;
                cout << " 2 - Excluir " << endl;
                cout << " 3 - Listar " << endl;
                cout << " 4 - Alternar " << endl;
                cout << " 5 - Ordenar " << endl << endl;
                cout << " 0 - Sair " << endl << endl;
                cout << "Digite aqui: ";

                cin >> opcao;

                
                    switch(opcao){
                        case 1: {

                            if(vetor == v_inicial)
                                pista = add_vetor(v_inicial, pista);

                            cout << " O nome da rodovia referida: ";
                            cin.ignore();
                            getline(cin, pista[vetor].nome);

                            cout << " Sua Extensão total: ";
                            cin >> pista[vetor].extensao;

                            cout << " Ano de sua inauguracao: ";
                            cin >> pista[vetor].ano;

                            cout << " Descricao detalhada da rodovia: ";
                            cin.ignore();
                            getline(cin, pista[vetor].descricao);

                            pista[vetor].flag = true;

                            aux++;
                            vetor++;

                            break;
                        }
                        case 2: {
                            cout << endl;
                            cout << " Selecione o numero do ID da pista a ser excluido: " << endl << endl;
                            for ( int i = 0; i <= aux; i++){
                                if ( pista[i].flag == true ){
                                    cout << " | [" << i << "]: ";
                                    cout << pista[i].nome << endl;
                                }
                            }
                            cin >> excluir;
                                for ( int i = 0; i <= aux; i++){
                                    if (i == excluir) 
                                        pista[i].flag = false; 
                                }
                                break;
                        }

                        case 3: {
                            for ( i = 0; i < vetor; i++){
                                if (pista[i].flag == true){
                            
                                    cout << endl << " | [ Identificador: " << i << " ]: " << endl << 
                                        " | Rodovia: " << pista[i].nome << "" << endl;

                                    cout << " | Sua Extensao e: ";
                                    cout << pista[i].extensao << endl;
                                    cout << " | Ano de sua inauguracao: ";
                                    cout << pista[i].ano << endl;
                                    cout << " | Descricao Tecnica: ";
                                    cout << pista[i].descricao << endl;
                                }                
                            }

                            cout << endl << " Quer Voltar ao menu, ou sair do programa ?" << endl;
                            cout << endl << endl <<" || 1 - Voltar " << endl <<" || 2 - Sair" << endl << endl << "Digite: ";

                            cin >> saida;

                            if (saida == 1) break;
                            else {
                                cout << " Obrigado por utilizar meu programa :)" << endl; 
                                delete [] pista;
                                return 0;
                            }
                            

                            break;
                        }
                        case 4: {
                            cout << " Selecione o identificador do nome a ser alterado: " << endl << endl;
                            for ( int i = 0; i <= vetor; i++)
                                    {
                                        if ( pista[i].flag == true )
                                        {
                                            cout << " | [" << i << "]: ";
                                            cout << pista[i].nome << endl;
                                        }
                                    }

                            cout << endl;

                            cin >> id_alterar;

                            cout << "Alterado com sucesso" << endl;
                            system("pause");
                            cout << endl;

                                    alterar(id_alterar, pista);

                                    break;
                        }
                        case 5: {
                           merge_sort(pista, 0, vetor-1);
                           cout << "Organizado em ordem alfabetica" << endl;
                        }
                    }
                }
            }while(opcao != 0);
        }
        default: {
            cout << "Obrigado por utilizar meu programa :)" << endl; 
            delete [] pista;
            break;
        }
    }
    return 0;
}