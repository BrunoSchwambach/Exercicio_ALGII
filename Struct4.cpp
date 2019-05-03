#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define TAMANHO 50
FILE *arq;
using namespace std;


typedef struct Pessoa{
	int id,idade;
	string nome;
	float salario;
};

Pessoa entrada(){
	Pessoa p;
	cout << "CADASTRO" << endl;
	cout << "---------" << endl;
	cout << "Codigo: ";
	cin >> p.id;
	fflush(stdin);
	cout << "Nome: ";
	getline(cin,p.nome);
	fflush(stdin);
	cout << "Idade: ";
	cin >> p.idade;
	fflush(stdin);
	cout << "Salario: ";
	cin >> p.salario;
	fflush(stdin);
	return p;
}
void menu(){	
	
	cout <<"\nMENU\n" << "----" << "\n1-Cadastrar" << "\n2-Consultar" << "\n3-Editar" << "\n4-Excluir" << "\n5-Relatorio" << "\n6-Relatorio de emprestimos" << "\n0-Sair"<<endl;
	return;

}

bool insere(Pessoa p, Pessoa vetor[], int *posicao){
    vetor[*posicao] = p;
    (*posicao)++;
    return true;
}

void mostrar(Pessoa pessoas[], int tamanho){
    for(int i=0; i<tamanho; i++){
        cout<< "-----"<<"\nDADOS" << "\nCodigo: " << pessoas[i].id << "\nNome: " << pessoas[i].nome 
        <<"\nIdade: " << pessoas[i].idade << "\nSalario: " << pessoas[i].salario << endl;
    }
}

bool salvar(Pessoa pessoas[], int tamanho){
    if ((arq = fopen("pessoas.txt","w")) == NULL) {
       return false;
    } else {
        for(int i=0;i<tamanho; i++){
		
            fwrite(&pessoas[i],sizeof(pessoas[i]),1,arq);
        	printf("%d", i);
		}	
	
        fclose(arq);
    }
    return true;
}


bool abrir(Pessoa pessoa[], int *tamanho){
	if((arq = fopen ("pessoas.txt", "r"))==NULL){
		return false;
	}else{
		while(true){
			fread(&pessoa[*tamanho], sizeof(Pessoa),1,arq);
			printf ("%d",*tamanho);
			if(feof(arq)){
				break;
		}
			(*tamanho)++;
				
			
		}
		fclose(arq);
	}
	return true;
}
void consultar(Pessoa pessoas[], int posicao){
	int cod;
	cout << "Digite um ID para ser consultado: " << endl;
	cin >> cod;
	for(int i=0;i<posicao;i++){
		if(pessoas[i].id == cod){
		 cout<< "-----"<<"\nDADOS" << "\nCodigo: " << pessoas[i].id << "\nNome: " << pessoas[i].nome 
        <<"\nIdade: " << pessoas[i].idade << "\nSalario: " << pessoas[i].salario << endl;
		}else{
			cout << "ID nao encontrado!" << endl;
		}
		
	} return;
}
void editar(Pessoa pessoas[], int posicao){
	int cod;
	cout << "Digite um ID para ser editado: " << endl;
	cin >> cod;
	for(int i=0;i<posicao;i++){
		if(pessoas[i].id == cod){
			cout << "Codigo: ";
			cin >> pessoas[i].id;
			fflush(stdin);
			cout << "Nome: ";
			getline(cin,pessoas[i].nome);
			fflush(stdin);
			cout << "Idade: ";
			cin >> pessoas[i].idade;
			fflush(stdin);
			cout << "Salario: ";
			cin >> pessoas[i].salario;
			fflush(stdin);
		}else{
			cout << "ID nao encontrado!" << endl;
		}
		
	} return;
}
void excluir(Pessoa pessoas[], int posicao){
	int cod;
	cout << "Digite um ID para ser excluido: " << endl;
	cin >> cod;
	for(int i=0;i<posicao;i++){
		if(pessoas[i].id == cod){
			pessoas[i].id=-1;
			fflush(stdin);
			pessoas[i].nome = " ";
			fflush(stdin);
			pessoas[i].idade=-1;
			fflush(stdin);
			pessoas[i].salario=-1;
			fflush(stdin);
		}else{
			cout << "ID nao encontrado!" << endl;
		}
		
	} return;
}

int main(){
    Pessoa pessoas[TAMANHO];
    int registro=0;
    abrir(pessoas, &registro);
    int opcao;
	do{
	menu();
	cout << "Sua opcao: " << endl;
	cin >> opcao;
		switch (opcao){
			case 1:
			insere(entrada(), pessoas, &registro);
			break;
			case 2: consultar(pessoas, registro);
			break;
			case 3: editar(pessoas, registro);
			break;
			case 4: excluir(pessoas, registro);
			break;
			case 5: mostrar(pessoas, registro);
			break;
			case 6: //relatorio de emprestimos
			break;
			case 0: salvar(pessoas, registro);
			break;
	}
    
}while(opcao!=0);
return 0;
}
