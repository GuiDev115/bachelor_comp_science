#include <iostream>

using namespace std;

//inicialização do refistro
struct compositor
{
	string nome;	
	int dia,mes,ano;
	string principal_obra;
	bool flag;

};

compositor *copia_vetor(compositor *novo,compositor *vet,int tam);

compositor *expande_vet(compositor *vet,int &tam)
{
	compositor *expandido = new compositor[tam + tam * 20 / 100]; //expanção dinamica do tamnaho do vetor
	copia_vetor(expandido,vet,tam);
	tam += tam * 20/100;
	return expandido;
}

compositor *copia_vetor(compositor *expandido,compositor *vet,int tam) // função para copiar o vetor passado para expandido
{
	for(int i = 0;i < tam;i++)
	{
		expandido[i].nome = vet[i].nome;
		expandido[i].dia = vet[i].dia;
		expandido[i].mes = vet[i].mes;
		expandido[i].ano = vet[i].ano;
		expandido[i].principal_obra = vet[i].principal_obra;
		expandido[i].flag = vet[i].flag;
	}
	
	delete []vet; // desaloca o vetor antigo
	return expandido; // retorna o novo vetor
}

void excluir(compositor *vet, int posicao_ocupadas, int posicao_excluir) // função para a exclusão do dado
{

    for ( int i = 0; i <= posicao_ocupadas; i++)
    {
        if (i == posicao_excluir) // encontra no vetor a posição desejada
        {
			vet[i].flag = false; // faz a exclusão logica dos dados
        }
        
    }
    
}

void listagem (compositor *vet, int posicao_ocupadas) //mostra o dados que compoem o vetor
{

    for ( int i = 0; i <= posicao_ocupadas; i++)
    {
        if (vet[i].flag == true) // testa se os dados são validos
        {
            cout << " | [" << i << "]: " << vet[i].nome << "";
            cout << endl;
            cout << " | Sua data de nascimento e: ";
            cout << vet[i].dia << "/" << vet[i].mes << "/" << vet[i].ano;
            cout << endl;
            cout << " | Sua principal obra e: ";
            cout << vet[i].principal_obra << "" << endl;
        }  
    }
}

void quick_sort_A(compositor *vet,int inicio, int fim) // faz a ordenação de a - z
{
    int i = inicio, j = fim;
    compositor pivo = vet[(inicio+fim)/2];
    while(i <= j)
    {
        while(vet[i].nome < pivo.nome and i < fim)
            i++;
        while(vet[j].nome > pivo.nome and j > inicio)
            j--;
        if(i <= j)
        {
            swap(vet[i],vet[j]);
            i++;
            j--;
        }
    }
}

void quick_sort_Z(compositor *vet,int inicio,int fim) // faz a ordenação de z - a
{
    int i = inicio, j = fim;
    compositor pivo = vet[(inicio+fim)/2];
    while(i <= j)
    {
        while(vet[i].nome > pivo.nome and i < fim)
            i++;
        while(vet[j].nome < pivo.nome and j > inicio)
            j--;
        if(i <= j)
        {
            swap(vet[i],vet[j]);
            i++;
            j--;
        }
    }
}

int main()
{

    int opcao_esc = 0;
    //Inicialização
    int tam = 5, posicao = -1;
    //Inserir
    int posicao_vetor = 0;
    //posição ocupada no vetor
    int compositor_excluir = 0;
    //Excluir
    int case4 = 0;
    int alterar = 0;
    //Alterar
    int ordenar = 0;
    //Ordenação

    cout << "Digite o numero de uma das opcoes abaixo: " << endl;
    cout <<" | " <<"Incluir (1)" << endl;
    cout <<" | " << "Sair    (2)" << endl;
    cout << endl;
    cout << "Insira a opcao desejada: ";

    cin >> opcao_esc;
    
    if (opcao_esc == 1) //caso a opção de escolha for a de inserção, é inserido o primeiro valor e as outras opções são habilitadas
    {
        compositor *compositores = new compositor[tam]; // alocação do vetor
                
        cin.ignore();
                
        cout <<" | Insira o nome do compositor: ";
        getline(cin,compositores[posicao_vetor].nome);
                
        cout << " | Insira a data de nascimento " << endl;
        cout << " | Insira o dia de nascimento: ";
        cin >> compositores[posicao_vetor].dia;
        
        cout << " | Insira o mes de nascimento: ";
        cin >> compositores[posicao_vetor].mes;
        
        cout << " | Insira o ano de nascimento: ";
        cin >> compositores[posicao_vetor].ano;
        cin.ignore();
                
        cout <<" | Insira a principal obra: ";
        getline(cin,compositores[posicao_vetor].principal_obra);
        compositores[posicao_vetor].flag = true; // Por padrão todos os compositores tem a flag definida como verdadeiro enquanto são dados validos
		
        posicao++;
        posicao_vetor++;
        
        while (opcao_esc != 6)
        {
			cout << endl;
			cout << endl;
            cout << "Digite o numero de uma das opcoes abaixo: " << endl;
            cout << endl;
            cout <<" | " << "Incluir (1)" << endl;
            cout <<" | " << "Excluir (2)" << endl;
            cout <<" | " << "Listar  (3)" << endl;
            cout <<" | " << "Alterar (4)" << endl;
            cout <<" | " << "Ordenar (5)" << endl;
            cout <<" | " << "Sair    (6)" << endl;
            cout << endl;
            cout << "Insira a opcao desejada: ";
            
            cin >> opcao_esc;

            switch (opcao_esc)
            {
                case 1:
                {   
					// Testa o tamanho do vetor
					
					if(posicao_vetor == tam)
                    {
                        compositores = expande_vet(compositores,tam);
                    }
					
                    cin.ignore();
                            
                    cout<<" | Insira o nome do compositor: ";
                    getline(cin,compositores[posicao_vetor].nome);
                            
                    cout << " | Insira a data de nascimento: " << endl;
                    cout << " | Insira o dia de nascimento: ";
                    cin >> compositores[posicao_vetor].dia;
                    
                    cout << " | Insira o mes de nascimento: ";
                    cin >> compositores[posicao_vetor].mes;

                    cout << " | Insira o ano de nascimento: ";
                    cin >> compositores[posicao_vetor].ano;

                    cin.ignore();
                            
                    cout <<" | Insira a principal obra: ";
                    getline(cin,compositores[posicao_vetor].principal_obra);

                    compositores[posicao_vetor].flag = true;
                    
                    posicao++;
                    posicao_vetor++;
                    break;
                }
                case 2: // exclusão de dados
                {
					cout << endl;
                    cout << " | Selecione o numero do compositor a ser excluido: " << endl;
                    for ( int i = 0; i <= posicao; i++)
                    {
                        if ( compositores[i].flag == true )
                        {
                            cout << " | [" << i << "]: ";
                            cout << compositores[i].nome << endl;
                        }
                    }
                    cin >> compositor_excluir;
                        excluir(compositores, posicao, compositor_excluir);
                        break;
                }
                case 3: // listagem de dados
                {    	
					listagem(compositores,posicao);
					break;
				
				}
                case 4: // alteração de dados
                {
                    cout << " | Selecione o que alterar: " << endl;
                    cout << " | (1) Nome" << endl;
                    cout << " | (2) Data de nascimento" << endl;
                    cout << " | (3) Principal obra" << endl;
                    cout << " | (4) Voltar ao menu" << endl;
                    
                    cin >> case4;
                    
                    cout << endl;

                    switch(case4)
                    {
                        case 1: // alterar o nome do usuario
                        {
                            cout << " | Selecione o identificador do nome a ser alterado: ";
                            cout << endl;
                            for ( int i = 0; i <= posicao; i++)
                            {
                                if ( compositores[i].flag == true )
                                {
                                    cout << " | [" << i << "]: ";
                                    cout << compositores[i].nome << endl;
                                }
                            }
                            cin >> alterar;
                            cout << " | Insira o Nome novo: ";
                            cin.ignore();
                            getline(cin, compositores[alterar].nome);
                            break;
                        }
                        case 2: // alterar a data de nascimento
                        {
                            cout << " | Selecione o identificador da data de nascimento a ser alterada: ";
                            cout << endl;
                            for ( int i = 0; i <= posicao; i++)
                            {
                                if ( compositores[i].flag == true )
                                {
                                    cout << " | [" << i << "]: ";
                                    cout << compositores[i].nome << " ";
                                    cout << compositores[i].dia << "/" << compositores[i].mes << "/" << compositores[i].ano;
                                    cout << endl;
                                }
                            }
                            cin >> alterar;
                            cout << " | Insira a DIA de nascimento novo: ";
                            cin >> compositores[alterar].dia;
                            cout << " | Insira a MES de nascimento novo: ";
                            cin >> compositores[alterar].mes;
                            cout << " | Insira a ANO de nascimento novo: ";
                            cin >> compositores[alterar].ano;
                            break;
                        }
                        case 3: // alterar obra principal
                        {
                            cout << " | Selecione Obra Principal a ser alterada: ";
                            cout << endl;
                            for (int i = 0; i <= posicao; i++)
                            {
                                if ( compositores[i].flag == true )
                                {
                                    cout << " | [" << i << "]: ";
                                    cout << compositores[i].nome << " ";
                                    cout << compositores[i].principal_obra << endl;
                                }
                            }
                            cin >> alterar;
                            cout << " | Insira a nova Obra Principal: ";
                            cin.ignore();
                            getline(cin, compositores[alterar].principal_obra);
                            break;
                        }
                        default: // retorna para o menu prinncipal
                        {
                            break;
                        }
                    }
                    break;
                }
                case 5: // faz a ordenação de dados
                {
                    cout << " | Escolha se deseja ordernar de forma alfabetica:" << endl;
                    cout << " | (1) De A pra Z" << endl << " | (2) De Z pra A" << endl;

                    cin >> ordenar;

                    if(ordenar == 1)
                        quick_sort_A(compositores,0,posicao);    

                    else if(ordenar == 2)
                        quick_sort_Z(compositores,0,posicao);

                    break;
                }
                case 6: // encerra o programa
                {
					delete [] compositores;
					break;
				}
				
                 default: // caso a opção selecionada seja invalida
                { 
                    cout << "Essa opcao nao existe, escolha outra opcao" << endl; // Mensagem retornada caso a opcao escolhida seja invalida
                    break;
                }
			} 
		} 
    }
    return 0;
}