#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
	char input1[11];
	char input2[11];
	int deger1;
	int deger2;
	int output;
	char outputt[11];
}gate;

void and_fonk(gate *and,int k);
void or_fonk(gate *or,int k);
void not_fonk(gate* not,int k);
void flip_fonk(gate* flip,int k);

typedef struct{
	char input[11];
	int val;
}value;

int main(){

	FILE * fp1;
	FILE * fp2;
	
	gate * kapi;
	value * deger;
	char name[11];
	char karakter;
	int sizeVal = 0;
	int gate_n = 0;
	int rowSize = 0;
	int sayi;
	int i = 0,a=0,t=0,sayac=0,n,flag=0,temp=0,flag1=0,flag2=0,tekrar_kapi=0;
	int j = 0;
	int k = 0;
	fp2 = fopen("circuit.txt","r");
	/*gate_n dosyadaki kapi sayisi sizeVal dosyadaki inputta bulunan degisken sayisi*/
	while(fscanf(fp2,"%s",name) != EOF){	/*circuit dosyasindaki input sayisi ve kapi sayisini saydim */
		if(strcmp(name,"INPUT") == 0){		
			while( (karakter =(fgetc(fp2))) != '\n'){	/*inputtaki degisken sayisinin sayisini sizeVal degiskenine attim */
				if(karakter == ' '){
					sizeVal++;
				}
			}
		}
		else if(strcmp(name,"OR") == 0){
			gate_n++;
		}
		else if(strcmp(name,"AND") == 0){
			gate_n++;
		}
		else if(strcmp(name,"FLIPFLOP") == 0){
			gate_n++;
		}
		else if(strcmp(name,"NOT") == 0){
			gate_n++;
		}
	}
	deger = malloc(sizeVal * sizeof(value));		/*input degiskenindeki ifadelere input degerlere atamalar yapacagim deger structini olusturdum*/
	kapi = malloc(gate_n * sizeof(gate));			/*gate tipinde*/

	fclose(fp2);
	
	fp1 = fopen("input.txt","r");			
	while( (karakter =fgetc(fp1)) != EOF){		/*inputtaki sayi satir sayisini hesapladim*/
		if(karakter == '\n'){
			rowSize++;
		}
	}
	fclose(fp1);
	
	fp1 = fopen("input.txt","r");
	fp2 = fopen("circuit.txt","r");
	while(i < rowSize){ 		/*inputtaki sayi satir sayisi kadar dönen ana döngü*/
		k=0;
		while(j<gate_n+1){		/*circuit dosyasinda saydigim kapi sayisi kadar donen dongu*/
			fscanf(fp2,"%s",name);
			if(strcmp(name,"INPUT") == 0){		/*circuit dosyasinda input kelimesi gormesi halinde input satirindaki degiskenlere deger atadigim sart ve dongu*/
				while( a<sizeVal){
					fscanf(fp2,"%s",name);
					strcpy(deger[a].input,name);	/*structa bu degiskenleri karsilastirabilmek icin degisken isimlerini atdim*/
				
					fscanf(fp1,"%d",&sayi);
					deger[a].val = sayi;			/*structa her degisken icin input dosyasindaki degerlerini attim*/
					a++;
				}
			}	
			else if(strcmp(name,"AND") == 0){		/*circuit dosyasinda AND kelimesi gormesi halinde o satirdaki degiskenleri atayip degerlere gore hesaplamalar yaptim*/
				fscanf(fp2,"%s",name);
				strcpy(kapi[k].outputt,name);
				
				fscanf(fp2,"%s",name);
				strcpy(kapi[k].input1,name);
				
				fscanf(fp2,"%s",name);
				strcpy(kapi[k].input2,name);
				
				while(t<=sizeVal){			/*input dosyasindaki sayi adeti kadar donen bir dongu kurdum*/
		/*structa attigim ifadeler circuit dosyasinin icindeki input satirindaki ifadeler ile karsılastirdigim kosullar*/		
					if(strcmp(kapi[k].input1,deger[t].input) == 0){		/*gate structindaki input1'yi ifadeyi circuitin inputun satirindaki ifadelerle karsilastirdim */
						kapi[k].deger1 = deger[t].val;
					}
					if(strcmp(kapi[k].input2,deger[t].input) == 0){		/*gate structindaki input2'yi ifadeyi circuitin inputun satirindaki ifadelerle karsilastirdim */
						kapi[k].deger2 = deger[t].val;
					}
					t++;
				}
				t=0;
				n=0;
/*circuitten okudugum ifadeler input satirindaki ifadelerle cakismiyorsa onceki structlara kaydettigim islemler sonucunda bir degeri olan
outputtaki degiskenlerle kiyasladim*/				
				while(n<=k){	/*o zamana kadar islem yaptigim gate sayisi kadar donen bu dongude outputtaki ifadelerle karsılastirma yaptim*/	
					if(strcmp(kapi[k].input1,kapi[n].outputt) == 0){
						kapi[k].deger1=kapi[n].output;
						flag1=1;
					}
					if(strcmp(kapi[k].input2,kapi[n].outputt) == 0){
						kapi[k].deger2=kapi[n].output;
						flag1=1;
					}
					n++;
				}
						if(flag1==0 || flag2==0 ){
							n=0;
							while(n<=k){
								if(strcmp(kapi[k].input1,kapi[n].outputt) == 0){
									kapi[k].deger1=kapi[n].output;
								}	
								if(strcmp(kapi[k].input2,kapi[n].outputt) == 0){
									kapi[k].deger2=kapi[n].output;									
								}
								n++;									
							}
						}
				flag1=0;
				flag2=0;						
				and_fonk(kapi,k); /*and fonksiyonunu cagirip struct icindeki degerlere gore and'leme islemi yaptigim fonskiyon*/
				k++;
			}
			else if(strcmp(name,"OR") == 0){	/*circuit dosyasinda OR kelimesi gormesi halinde o satirdaki degiskenleri atayip degerlere gore hesaplamalar yaptim*/
				fscanf(fp2,"%s",name);
				strcpy(kapi[k].outputt,name);
				
				fscanf(fp2,"%s",name);
				strcpy(kapi[k].input1,name);
				
				fscanf(fp2,"%s",name);
				strcpy(kapi[k].input2,name);
								
				while(t<=sizeVal){	/*input dosyasindaki sayi adeti kadar donen bir dongu kurdum*/
		/*structa attigim ifadeler circuit dosyasinin icindeki input satirindaki ifadeler ile karsılastirdigim kosullar*/
					if(strcmp(kapi[k].input1,deger[t].input) == 0){
						kapi[k].deger1 = deger[t].val;
					}
					if(strcmp(kapi[k].input2,deger[t].input) == 0){
						kapi[k].deger2 = deger[t].val;
					}
					t++;
				}
				t=0;
				n=0;
/*circuitten okudugum ifadeler input satirindaki ifadelerle cakismiyorsa onceki structlara kaydettigim islemler sonucunda bir degeri olan
outputtaki degiskenlerle kiyasladim*/
				while(n<=k){	/*o zamana kadar islem yaptigim gate sayisi kadar donen bu dongude outputtaki ifadelerle karsılastirma yaptim*/	
					if(strcmp(kapi[k].input1,kapi[n].outputt) == 0){
						kapi[k].deger1=kapi[n].output;
					}
					if(strcmp(kapi[k].input2,kapi[n].outputt) == 0){
						kapi[k].deger2=kapi[n].output;
					}
					n++;
				}				
				or_fonk(kapi,k);		/*or fonksiyonunu cagirip struct icindeki degerlere gore or'lama islemi yaptigim fonskiyon*/
			k++;	

			}
			else if(strcmp(name,"NOT") == 0){ 	/*circuit dosyasinda NOT kelimesi gormesi halinde o satirdaki degiskenleri atayip degerlere gore hesaplamalar yaptim*/
				fscanf(fp2,"%s",name);
				strcpy(kapi[k].outputt,name);
				
				fscanf(fp2,"%s",name);
				strcpy(kapi[k].input1,name);
/*input dosyasindaki sayi adeti kadar donen bir dongu kurdum ve input satirindaki ifadeler ile kiyasladim*/				
				while(t<=sizeVal){						
					if(strcmp(kapi[k].input1,deger[t].input) == 0){
						kapi[k].deger1 = deger[t].val;
						flag=1;
					}
					t++;					
				}
						if(flag==0){	/*input satirindeki ifadelerle eslesmeyen durum icin koydugum kosul*/
							n=0;
							while(n<=k){	/*o zamana kadar islem yaptigim gate sayisi kadar donen bu dongude outputtaki ifadelerle karsılastirma yaptim*/	
								if(strcmp(kapi[k].input1,kapi[n].outputt) == 0){
									kapi[k].deger1=kapi[n].output;
								}
								n++;
							}								
						}				
				t=0;	
				flag=0;			
			not_fonk(kapi,k);	/*not fonksiyonunu cagirip struct icindeki degerlere gore not'lama islemi yaptigim fonskiyon*/
			k++;
			}
			else if(strcmp(name,"FLIPFLOP") == 0){	/*circuit dosyasinda FLIPFLOP kelimesi gormesi halinde o satirdaki degiskenleri atayip degerlere gore hesaplamalar yaptim*/
				fscanf(fp2,"%s",name);
				strcpy(kapi[k].outputt,name);
				
				fscanf(fp2,"%s",name);
				strcpy(kapi[k].input1,name);
				
				strcpy(kapi[k].input2,"former_out");
				
				if(sayac==0 ){	/*bir tane ve birden fazla flipflop islemleri icin iki ayri kosul yazdim ama verimlilik olarak gereksiz cok fazla denemeden sonra bozulmamasi icisindan silmedim*/
					while(t<=sizeVal){		/*input satirindaki ifadelerle karsilastirdigim dongu*/
						if(strcmp(kapi[k].input1,deger[t].input) == 0){
							kapi[k].deger1 = deger[t].val;
							flag=1;
						}
						t++;
					}
						if(flag==0){
							n=0;
							while(n<=k){	/*o zamana kadar islem yaptigim gate sayisi kadar donen bu dongude outputtaki ifadelerle karsılastirma yaptim*/
								if(strcmp(kapi[k].input1,kapi[n].outputt) == 0){
									kapi[k].deger1=kapi[n].output;
								}
								n++;
							}								
						}
					t=0;
					flag=0;
					sayac++;									
				}
				
				else{	/*birden fazla flipflop iceren islemler icin dusundugum kosul*/
					while(t<=sizeVal){	/*input satirindaki ifadelerle karsilastirdigim dongu*/
						if(strcmp(kapi[k].input1,deger[t].input) == 0){
							kapi[k].deger1 = deger[t].val;
							flag=1;
						}
						t++;
					}
						if(flag==0){
							n=0;
							while(n<=k){	/*o zamana kadar islem yaptigim gate sayisi kadar donen bu dongude outputtaki ifadelerle karsılastirma yaptim*/
								if(strcmp(kapi[k].input1,kapi[n].outputt) == 0){
									kapi[k].deger1=kapi[n].output;
								}
								n++;
							}								
						}
					t=0;
					flag=0;										
				}
			flip_fonk(kapi,k);	/*flipflop fonksiyonunu cagirip struct icindeki degerlere gore flipflop islemi yaptigim fonskiyon*/
			k++;					
			}
		t=0;		
		++j;
		}
		printf("%d\n",kapi[k-1].output);	/*verilen inputlara gore en son bastirdigim output degerleri*/
		fclose(fp2);
		fp2=fopen("circuit.txt","r");	/*her sonlanan circuit icin tekrar dosyayi acarak dongu tekrarinda en bastan okuma islemlerini yaptirdim*/
		a=0;
		j=0;
		sayac=0;		
	++i;
	}
	fclose(fp2);	/*dosyayi isim bittikten sonra kapattim*/
	fclose(fp1);	/*dosyayi isim bittikten sonra kapattim*/
	free(deger);	/*ayirdigim yeri serbest biraktim*/
	free(kapi);		/*ayirdigim yeri serbest biraktim*/
}	
	
void and_fonk(gate* and,int k){		/*and operatoruna gore output bulma islemleri*/
	if(and[k].deger1==1 && and[k].deger2==1){
		and[k].output=1;
	}
	else if(and[k].deger1==1 && and[k].deger2==0){
		and[k].output=0;
	}
	else if(and[k].deger1==0 && and[k].deger2==1){
		and[k].output=0;
	}
	else if(and[k].deger1==0 && and[k].deger2==0){
		and[k].output=0;
	}
	
}

void or_fonk(gate* or,int k){		/*or operatoruna gore output bulma islemleri*/
	if(or[k].deger1==1 && or[k].deger2==1){
		or[k].output=1;
	}
	else if(or[k].deger1==1 && or[k].deger2==0){
		or[k].output=1;
	}
	else if(or[k].deger1=='0' && or[k].deger2==1){
		or[k].output=1;
	}
	else if(or[k].deger1==0 && or[k].deger2==0){
		or[k].output=0;
	}
}

void not_fonk(gate* not,int k){		/*not operatoruna gore output bulma islemleri*/
	if(not[k].deger1==1){
		not[k].output=0;
	}
	if(not[k].deger1==0){
		not[k].output=1;
	}
}

void flip_fonk(gate* flip,int k){	/*flip_flop operatoruna gore output bulma islemleri*/
	/*deger2'lere tekrardan 0 atarak diger gateler icin farkli islemler yapabilir kildim */
	if(flip[k].deger1==1 && flip[k].deger2==1){
		flip[k].deger2=0;
		flip[k].output=0;
	}
	else if(flip[k].deger1==1 && flip[k].deger2==0){
		flip[k].deger2=1;
		flip[k].output=1;
	}
	else if(flip[k].deger1=='0' && flip[k].deger2==1){
		flip[k].deger2=1;
		flip[k].output=1;
	}
	else if(flip[k].deger1==0 && flip[k].input2==0){
		flip[k].deger2=0;
		flip[k].output=0;
	}
}













