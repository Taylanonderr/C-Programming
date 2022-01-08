#include<stdio.h>
void recurs(FILE *dosya,int sayac);
void printminus(int sayac);

int main(){

	FILE *dosya;
	dosya=fopen("input.txt","r");	/*dosyayi okumak icin actim*/
	recurs(dosya,0);		/*recursion yaptigim fonksiyonu cagirdim*/
	fclose(dosya);		
	}

void recurs(FILE *dosya, int sayac){		/*recursion yaptigim fonksiyon bastirma islemlerini burda yapiyorum*/
	char x;		/*okudugum karakteri attigim char karakter*/
	x=fgetc(dosya);			/*karakter okudugum yer*/
	if(x != EOF && x!= '\n' && x!= '\0'){
		if(x=='('){		/*parantez acma görünce tire bastirma sayisini arttirdigim kosul*/
			sayac++;
		}
		else if(x==')'){	/*parantez kapama gorunce tire bastirma sayisini azalttigim kosul*/
			sayac--;
		}
		else if(x!='(' && x!=')' &&x!=','){		/*harf haricindeki ifadeleri bastirmadigim kosul*/
			printminus(sayac);	/*'-' işaretini bastirdigim fonksiyon*/
			printf("%c\n",x);	/* parantez ve virgul harici okudugum karakterleri bastirdigim kisim*/
		}
		recurs(dosya,sayac);	/*fonksiyonu tekrar tekrar çagirdigim recursion kismi*/
	}
}

void printminus(int sayac){		/*tireleri bastirdigim diger recursion fonksiyonu*/
	if(sayac >0){		/*tire sayisi icin koydugum kosul*/
		printf("-");
		printminus(sayac-1);	/*recursionı sinirlandirdigim kisim*/
	}
}
