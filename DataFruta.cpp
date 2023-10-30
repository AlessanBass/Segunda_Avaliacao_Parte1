#include <iostream>
#include <string>
#include <vector>
#include <algorithm>  // Inclua a biblioteca algorithm para usar o sort

using namespace std;

class Data {
	int dia, mes, ano;
	public:
	
	/*
	O método abaixo pergunta ao usuários quantos
	elementos vão existir na lista e depois
	solicita a digitação de cada um deles
	*/	
	static int compara(Data d1, Data d2) { 
		if (d1.ano < d2.ano){
			return -1;
		}else if (d1.ano > d2.ano){
            return 1;
		}else {
            if (d1.mes < d2.mes){
                return -1;
			}else if (d1.mes > d2.mes){
                return 1;
			}else {
                if (d1.dia < d2.dia){
                    return -1;
				}else if (d1.dia > d2.dia){
                    return 1;
				}else{
                    return 0;
				}
            }
        }
	}
	
	Data (int _dia, int _mes, int _ano) {
		dia = _dia;
		mes = _mes;
		ano = _ano;
	}
	string toString() {
		string ret = "";
		ret.append(to_string(dia));
		ret.append("/");
		ret.append(to_string(mes));
		ret.append("/");
		ret.append(to_string(ano));
		return ret;
	}
};

class Lista {
	public:
	virtual void entradaDeDados() =0;
	virtual void mostraMediana() =0;
	virtual void mostraMenor() =0;
	virtual void mostraMaior() =0;
};

class ListaNomes  {
	vector<string> lista;
	
	public:
	
	/*
	O método abaixo pergunta ao usuários quantos
	elementos vão existir na lista e depois
	solicita a digitação de cada um deles
	*/	
	void entradaDeDados() {
		lista.push_back("Teste");
	}
		
	void mostraMediana() {
		cout << "Aqui vai mostrar a mediana da lista de strings" << endl;
	}
	
	void mostraMenor() {
		cout << "Aqui vai mostrar o primeiro nome alfabeticamente" << endl;
	}
	void mostraMaior() {
		cout << "aqui vai mostrar o ultimo nome alfabeticamente" << endl;
	}
};

class ListaDatas : public Lista {
	vector<Data> lista;
	
	public:
		
	/*
	O método abaixo pergunta ao usuários quantos
	elementos vão existir na lista e depois
	solicita a digitação de cada um deles
	*/	
	void entradaDeDados() override {
		int quantidade, dia, mes, ano;
		
		cout << "Deseja inserir quantos elementos na lista de datas ?" << endl;
		cin >> quantidade;
		cin.ignore();

		for(int i =0; i<quantidade; i++){
			cout << "---- DATA: " << i+1  << " -------"<< endl;
			cout << "Informe o dia: " << endl;
			cin >> dia;

			cout << "Informe o mes: " << endl;
			cin >> mes;

			cout << "Informe o ano: " << endl;
			cin >> ano;

			Data data(dia, mes, ano);

			lista.push_back(data);
		} 
		
		selectionSortAdaptado(lista);
		exibeLista();
	}
	
	void mostraMediana() override {
		Data mediana(0,0,0);
		int tamanho = lista.size();

		cout << ">>> MEDIANA DA LISTA DE NOMES: " << endl;

		if (tamanho % 2 == 1) {
			// Tamanho ímpar, a mediana é o elemento do meio
			mediana = lista[tamanho / 2];
			cout << "Mediana da lista de datas: " << mediana.toString() << endl;
    	} else {
			// Tamanho par, a mediana é o primeiro dos dois nomes em ordem alfabética
			mediana = lista.front();
			cout << "Mediana da lista de nomes: " << mediana.toString() << endl;
  	    }
	}
	
	void mostraMenor() override {
		Data menor = lista.front();
		cout << ">>> MOSTRANDO A PRIMEIRA DATA CRONOLOGICAMENTE: " << endl;
		cout << "Primeira data: " << menor.toString() << endl;
	}
	void mostraMaior() override {
		Data maior = lista.back();
		cout << ">>> MOSTRANDO A ULTIMA DATA CRONOLOGICAMENTE: " << endl;
		cout << "Ultima data: " << maior.toString() << endl;
	}

	void exibeLista (){
		cout << "------------------------" << endl;
		for(auto elemento : lista){
			cout << elemento.toString() << endl;
		}
	}

	void selectionSortAdaptado(vector<Data> &datas){
		int minIndex, retornoComparacao;
		Data auxdData(0,0,0);
		for(int i = 0; i<datas.size() - 1; i++){
			minIndex = i;
			for(int j = i+1; j < datas.size(); j++){
				retornoComparacao = Data::compara(datas[j], datas[minIndex]);
				if(retornoComparacao == -1){
					minIndex = j;
				}
			}
			auxdData = datas[i];
			datas[i] = datas[minIndex];
			datas[minIndex] = auxdData;
		}
	}
};

class ListaSalarios : public Lista  { 
	vector<float> lista;
	
	public:
	
	/*
	O método abaixo pergunta ao usuários quantos
	elementos vão existir na lista e depois
	solicita a digitação de cada um deless
	*/	
	void entradaDeDados()override {
		int quantidade;
		float salario;

		cout << "Quantos salarios deseja inserir na list: " << endl;
		cin >> quantidade;
		cin.ignore();

		for (int i = 0; i<quantidade; i++ ) {
			cout << "Digite o salario: " << endl;
			cin >> salario;

			lista.push_back(salario);
		}
		sort(lista.begin(),lista.end());
	}
			
	void mostraMediana()override {
		int tamanho;
		float mediana;

		tamanho = lista.size();
		
		if (tamanho % 2 == 1 ) {
			mediana = lista[tamanho/2];
			cout << "A mediana e: " << mediana << endl;
		} else {
			mediana = (lista[tamanho / 2 - 1] + lista[tamanho / 2]) / 2.0;
			cout << "A mediana e: " << mediana << endl;
		}
	}
	
	void mostraMenor()override {
		cout << "O menor salario e: " << lista.front() << endl;
		
	}
	void mostraMaior()override {
		cout << "O maior salario e: " << lista.back() << endl;
	}

};


class ListaIdades  {
	vector<int> lista;
	
	public:
		
		/*
	O método abaixo pergunta ao usuários quantos
	elementos vão existir na lista e depois
	solicita a digitação de cada um deles
	*/	
	void entradaDeDados() {
		
	}
	
	void mostraMediana() {
		cout << "Aqui vai mostrar a mediana da lista de idades" << endl;
	}
	
	void mostraMenor() {
		cout << "Aqui vai mostrar a menor das idades" << endl;
	}
	void mostraMaior() {
		cout << "aqui vai mostrar a maior das idades" << endl;
	}
};
 
int main () {
	vector<Lista*> listaDeListas;
	
	ListaNomes listaNomes;
	listaNomes.entradaDeDados();
	listaDeListas.push_back(&listaNomes);
	
	ListaDatas listaDatas;
	listaDatas.entradaDeDados();
	listaDeListas.push_back(&listaDatas);
	
	ListaSalarios listaSalarios;
	listaSalarios.entradaDeDados();
	listaDeListas.push_back(&listaSalarios);
	
	ListaIdades listaIdades;
	listaIdades.entradaDeDados();
	listaDeListas.push_back(&listaIdades);

	
	for (Lista* l : listaDeListas) {
		l->mostraMediana();
		l->mostraMenor();
		l->mostraMaior();
	}
	
}
    

