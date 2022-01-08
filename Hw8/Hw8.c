#include<stdio.h>
#include<stdlib.h>
typedef struct{ 
	int** array;        /*2 boyutlu her yuz icin farkli array tanimladim*/
}rubic;

void copy_fonk(rubic* kup,int array[],int boyut,int yuz,int koor);
void copy_fonk_col(rubic* kup,int array[],int boyut,int yuz,int koor);
void paste_fonk(rubic* kup,int array[],int boyut,int yuz,int koor);
void paste_fonk_col(rubic* kup,int array[],int boyut,int yuz,int koor);
void copy_fonk_reverse(rubic* kup,int array[],int boyut,int yuz,int koor);
void paste_fonk_reverse(rubic* kup,int array[],int boyut,int yuz,int koor);
void copy_fonk_col_reverse(rubic* kup,int array[],int boyut,int yuz,int koor);
void paste_fonk_col_reverse(rubic* kup,int array[],int boyut,int yuz,int koor);
void copy_fonk_ters(rubic* kup,int array[],int boyut,int yuz,int koor);
void paste_fonk_ters(rubic* kup,int array[],int boyut,int yuz,int koor);
void copy_fonk_col_ters(rubic* kup,int array[],int boyut,int yuz,int koor);
void paste_fonk_col_ters(rubic* kup,int array[],int boyut,int yuz,int koor);
void paste_fonk_col_reverse_ters(rubic* kup,int array[],int boyut,int yuz,int koor);
void paste_fonk_reverse_ters(rubic* kup,int array[],int boyut,int yuz,int koor);

int main(){
	FILE* fp1;      /*okuma islemi icin olusturdum*/
	FILE* fp2;      /*yazma islemi icin olusturdum*/
	rubic kup[6];   /*yukarida belirttigim struct tipinde kupun yuzleri icin 6 tane struct tanimladim*/
	int i,sayi,move,face,boyut,row,column,t;
	char bolge[7],yon[7],x[7];
	fp1=fopen("commands.txt","r");  /*okuma yapacagim dosyayi actim*/
	fscanf(fp1,"%d",&boyut);    /*struct icinde her yuz icin olusturacagim arrayin boyunu belirleme islemi icin dosyadan okudum*/
	for(i=0;i<6;i++){	/*struct icinde 2 boyutlu arrayi yer ayirarak olusturdum*/
		kup[i].array=(int **)malloc(boyut*sizeof(int*));	/*arrayin ilk boyutu icin yer ayirdim*/

		for(t=0;t<boyut;t++){
			kup[i].array[t] = malloc( boyut * sizeof(int) );	/*arrayin ikinci boyutu icin yer ayirdim*/
		}

	}
	
	int temp[boyut];
	int temp2[boyut];
	for(i=0;i<6;i++){		/*her yüzdeki arraylerin icine sayilari atadim*/
		for(column=0;column<boyut;column++){	
			for(row=0;row<boyut;row++){
				kup[i].array[column][row]=i;
			}
		}	
	}
	/*her yuz icin satir ve sutunlar olmak uzere dondurulme yonlerininde icinde oldugu kosullara gore
	fonksiyonlar esliginde islemler yaptim fonksiyonlarin ne olduklarini en altta teker teker acikladim
	face 0 row 0 icin yaptigim aciklamalar diger yuz ve kosullar icinde ayni*/
	
	while(fscanf(fp1,"%s",x)!=EOF){	/*dosyadan okuma islemi yaparak ona gore dondurme islemlerini yaptigim kisim*/
		if(strcmp(x,"rotate")==0){
			fscanf(fp1,"%d",&face);	/*dosyadaki yuzun sayisini okudum*/
			fscanf(fp1,"%s",bolge);	/*satir ve sutun icin okuma islemi yaptim*/
			fscanf(fp1,"%d",&move);	/*dondurme islemi yapilicak koordinati okudum*/
			fscanf(fp1,"%s",yon);	/*dondurme yonunu okudum*/
			
			if(strcmp(bolge,"row")==0 && face==0){	/*0.yüz icin satiri sağa sola kaydirma islemi*/
				copy_fonk(kup,temp,boyut,face,move);	/*0.yüzü kopyaladim*/
				if(strcmp(yon,"right")==0){		/*0.yüzde saga kaydirma islemlerini yaptirdim*/
					copy_fonk(kup,temp2,boyut,1,move);	/*1.yüzü kopyaladim*/
					paste_fonk(kup,temp,boyut,1,move);	/*1.yüze yapistirdim*/				
					copy_fonk(kup,temp,boyut,2,move);	/*2.yüzü kopyaladim*/
					paste_fonk(kup,temp2,boyut,2,move);	/*2.yüze yapistirdim*/
					copy_fonk(kup,temp2,boyut,3,move);	/*3.yüzü kopyaladim	*/
					paste_fonk(kup,temp,boyut,3,move);	/*3.yüze yapistirdim*/
					paste_fonk(kup,temp2,boyut,0,move);	/*0.yüze yapistirdim*/																						
				}
				else if(strcmp(yon,"left")==0){		/*0.yüzde sola kaydirma islemlerini yaptirdim*/
					copy_fonk(kup,temp2,boyut,3,move);	/*3.yuzu kopyaladim*/
					paste_fonk(kup,temp,boyut,3,move);	/*3.yuze onceki yuzu kaydirdim*/				
					copy_fonk(kup,temp,boyut,2,move);	/*2.yuzu kopyaladim*/
					paste_fonk(kup,temp2,boyut,2,move);	/*2.yuze onceki yuzu kaydirdim*/
					copy_fonk(kup,temp2,boyut,1,move);	/*1.yuzu kopyaladim*/	
					paste_fonk(kup,temp,boyut,1,move);	/*1.yuze onceki yuzu kaydirdim*/
					paste_fonk(kup,temp2,boyut,0,move);	/*0.yuze onceki yuzu kaydirdim*/				
				}
			}	
			else if(strcmp(bolge,"row")==0 && face==1){	/*1.yüzde satiri sağa sola kaydirma islemi*/
				copy_fonk(kup,temp,boyut,face,move);
				if(strcmp(yon,"right")==0){
					copy_fonk(kup,temp2,boyut,2,move);	
					paste_fonk(kup,temp,boyut,2,move);					
					copy_fonk(kup,temp,boyut,3,move);
					paste_fonk(kup,temp2,boyut,3,move);	
					copy_fonk(kup,temp2,boyut,0,move);		
					paste_fonk(kup,temp,boyut,0,move);
					paste_fonk(kup,temp2,boyut,1,move);						
				}
				else if(strcmp(yon,"left")==0){
					copy_fonk(kup,temp2,boyut,0,move);	
					paste_fonk(kup,temp,boyut,0,move);					
					copy_fonk(kup,temp,boyut,3,move);
					paste_fonk(kup,temp2,boyut,3,move);	
					copy_fonk(kup,temp2,boyut,2,move);		
					paste_fonk(kup,temp,boyut,2,move);
					paste_fonk(kup,temp2,boyut,1,move);				
				}		
			}
			else if(strcmp(bolge,"row")==0 && face==2){	//2.yüzde satiri sağa sola kaydirma
				copy_fonk(kup,temp,boyut,face,move);
				if(strcmp(yon,"right")==0){
					copy_fonk(kup,temp2,boyut,3,move);	
					paste_fonk(kup,temp,boyut,3,move);					
					copy_fonk(kup,temp,boyut,0,move);
					paste_fonk(kup,temp2,boyut,0,move);	
					copy_fonk(kup,temp2,boyut,1,move);		
					paste_fonk(kup,temp,boyut,1,move);
					paste_fonk(kup,temp2,boyut,2,move);						
				}
				else if(strcmp(yon,"left")==0){
					copy_fonk(kup,temp2,boyut,1,move);	
					paste_fonk(kup,temp,boyut,1,move);					
					copy_fonk(kup,temp,boyut,0,move);
					paste_fonk(kup,temp2,boyut,0,move);	
					copy_fonk(kup,temp2,boyut,3,move);		
					paste_fonk(kup,temp,boyut,3,move);
					paste_fonk(kup,temp2,boyut,2,move);				
				}		
			}
			else if(strcmp(bolge,"row")==0 && face==3){	//3.yüzde satiri sağa sola kaydirma
				copy_fonk(kup,temp,boyut,face,move);
				if(strcmp(yon,"right")==0){
					copy_fonk(kup,temp2,boyut,0,move);	
					paste_fonk(kup,temp,boyut,0,move);					
					copy_fonk(kup,temp,boyut,1,move);
					paste_fonk(kup,temp2,boyut,1,move);	
					copy_fonk(kup,temp2,boyut,2,move);		
					paste_fonk(kup,temp,boyut,2,move);
					paste_fonk(kup,temp2,boyut,3,move);						
				}
				else if(strcmp(yon,"left")==0){
					copy_fonk(kup,temp2,boyut,2,move);	
					paste_fonk(kup,temp,boyut,2,move);					
					copy_fonk(kup,temp,boyut,1,move);
					paste_fonk(kup,temp2,boyut,1,move);	
					copy_fonk(kup,temp2,boyut,0,move);		
					paste_fonk(kup,temp,boyut,0,move);
					paste_fonk(kup,temp2,boyut,3,move);					
				}			
			}
			else if(strcmp(bolge,"row")==0 && face==4){	//4.yüzde satiri sağa sola kaydirma	------BURDA KALDIM--------

				if(strcmp(yon,"right")==0){
					copy_fonk(kup,temp,boyut,face,move);
					copy_fonk_col_reverse(kup,temp2,boyut,1,move);	
					paste_fonk_col_reverse(kup,temp,boyut,1,move);					
					copy_fonk_reverse(kup,temp,boyut,5,move);
					paste_fonk_reverse(kup,temp2,boyut,5,move);	
					copy_fonk_col_ters(kup,temp2,boyut,3,move);		
					paste_fonk_col(kup,temp,boyut,3,move);
					paste_fonk(kup,temp2,boyut,4,move);						
				}
				else if(strcmp(yon,"left")==0){
					copy_fonk_ters(kup,temp,boyut,face,move);			
					copy_fonk_col(kup,temp2,boyut,3,move);	
					paste_fonk_col(kup,temp,boyut,3,move);					
					copy_fonk_reverse(kup,temp,boyut,5,move);
					paste_fonk_reverse(kup,temp2,boyut,5,move);	
					copy_fonk_col(kup,temp2,boyut,1,move);		
					paste_fonk_col_reverse_ters(kup,temp,boyut,1,move);		
					paste_fonk(kup,temp2,boyut,4,move);					
				}				
			}
			else if(strcmp(bolge,"row")==0 && face==5){	//5.yüzde satiri sağa sola kaydirma
				if(strcmp(yon,"right")==0){
					copy_fonk_ters(kup,temp,boyut,face,move);			
					copy_fonk_col(kup,temp2,boyut,1,move);	
					paste_fonk_col(kup,temp,boyut,1,move);				
					copy_fonk_ters(kup,temp,boyut,4,move);		
					paste_fonk_reverse(kup,temp2,boyut,4,move);	
					copy_fonk_col_reverse(kup,temp2,boyut,3,move);		
					paste_fonk_col_reverse(kup,temp,boyut,3,move);
					paste_fonk(kup,temp2,boyut,5,move);						
				}
				else if(strcmp(yon,"left")==0){
					copy_fonk(kup,temp,boyut,face,move);							
					copy_fonk_col_reverse(kup,temp2,boyut,3,move);	
					paste_fonk_col_reverse(kup,temp,boyut,3,move);					
					copy_fonk_reverse(kup,temp,boyut,4,move);
					paste_fonk_reverse_ters(kup,temp2,boyut,4,move);	
					copy_fonk_col_ters(kup,temp2,boyut,1,move);		
					paste_fonk_col(kup,temp,boyut,1,move);
					paste_fonk(kup,temp2,boyut,5,move);					
				}
			}
			else if(strcmp(bolge,"column")==0 && face==0){	//0.yüzde satiri asagi yukari kaydirma
				copy_fonk_col(kup,temp,boyut,face,move);
				if(strcmp(yon,"up")==0){
					copy_fonk_col_ters(kup,temp2,boyut,4,move);	
					paste_fonk_col(kup,temp,boyut,4,move);	
					copy_fonk_col_reverse(kup,temp,boyut,2,move);
					paste_fonk_col_reverse(kup,temp2,boyut,2,move);	
					copy_fonk_col(kup,temp2,boyut,5,move);		
					paste_fonk_col_ters(kup,temp,boyut,5,move);
					paste_fonk_col(kup,temp2,boyut,0,move);						
				}
				else if(strcmp(yon,"down")==0){
					copy_fonk_col_ters(kup,temp2,boyut,5,move);	
					paste_fonk_col(kup,temp,boyut,5,move);					
					copy_fonk_col_reverse(kup,temp,boyut,2,move);
					paste_fonk_col_reverse(kup,temp2,boyut,2,move);	
					copy_fonk_col(kup,temp2,boyut,4,move);		
					paste_fonk_col_ters(kup,temp,boyut,4,move);
					paste_fonk_col(kup,temp2,boyut,0,move);	
				}			
			}
			else if(strcmp(bolge,"column")==0 && face==1){	//1.yüzde satiri asagi yukari kaydirma
				copy_fonk_col(kup,temp,boyut,face,move);
				if(strcmp(yon,"up")==0){
					copy_fonk_reverse(kup,temp2,boyut,4,move);	
					paste_fonk_reverse(kup,temp,boyut,4,move);					
					copy_fonk_col_reverse(kup,temp,boyut,3,move);
					paste_fonk_col_reverse_ters(kup,temp2,boyut,3,move);	
					copy_fonk(kup,temp2,boyut,5,move);		
					paste_fonk(kup,temp,boyut,5,move);
					paste_fonk_col_ters(kup,temp2,boyut,1,move);							
				}
				else if(strcmp(yon,"down")==0){
					copy_fonk(kup,temp2,boyut,5,move);	
					paste_fonk_ters(kup,temp,boyut,5,move);					
					copy_fonk_col_reverse(kup,temp,boyut,3,move);
					paste_fonk_col_reverse(kup,temp2,boyut,3,move);	
					copy_fonk_reverse(kup,temp2,boyut,4,move);		
					paste_fonk_reverse_ters(kup,temp,boyut,4,move);
					paste_fonk_col(kup,temp2,boyut,1,move);					
				}
			}
			else if(strcmp(bolge,"column")==0 && face==2){	//2.yüzde satiri asagi yukari kaydirma9+
				copy_fonk_col_ters(kup,temp,boyut,face,move);
				if(strcmp(yon,"up")==0){
					copy_fonk_col_reverse(kup,temp2,boyut,4,move);	
					paste_fonk_col_reverse(kup,temp,boyut,4,move);					
					copy_fonk_col_reverse(kup,temp,boyut,0,move);
					paste_fonk_col_reverse(kup,temp2,boyut,0,move);	
					copy_fonk_col_reverse(kup,temp2,boyut,5,move);		
					paste_fonk_col_reverse(kup,temp,boyut,5,move);
					paste_fonk_col_ters(kup,temp2,boyut,2,move);								
				}
				else if(strcmp(yon,"down")==0){			
					copy_fonk_col_reverse(kup,temp2,boyut,5,move);	
					paste_fonk_col_reverse(kup,temp,boyut,5,move);					
					copy_fonk_col_reverse(kup,temp,boyut,0,move);
					paste_fonk_col_reverse(kup,temp2,boyut,0,move);	
					copy_fonk_col_reverse(kup,temp2,boyut,4,move);		
					paste_fonk_col_reverse(kup,temp,boyut,4,move);
					paste_fonk_col_ters(kup,temp2,boyut,2,move);					
				}
			}
			else if(strcmp(bolge,"column")==0 && face==3){	//3.yüzde satiri asagi yukari kaydirma
				if(strcmp(yon,"up")==0){
					copy_fonk_col(kup,temp,boyut,face,move);			
					copy_fonk(kup,temp2,boyut,4,move);	
					paste_fonk_ters(kup,temp,boyut,4,move);					
					copy_fonk_col_reverse(kup,temp,boyut,1,move);
					paste_fonk_col_reverse(kup,temp2,boyut,1,move);	
					copy_fonk(kup,temp2,boyut,5,move);		
					paste_fonk_reverse_ters(kup,temp,boyut,5,move);
					paste_fonk_col(kup,temp2,boyut,3,move);							
				}
				else if(strcmp(yon,"down")==0){
					copy_fonk_col(kup,temp,boyut,face,move);			
					copy_fonk_reverse(kup,temp2,boyut,5,move);	
					paste_fonk_reverse(kup,temp,boyut,5,move);					
					copy_fonk_col_reverse(kup,temp,boyut,1,move);
					paste_fonk_col_reverse_ters(kup,temp2,boyut,1,move);	
					copy_fonk(kup,temp2,boyut,4,move);		
					paste_fonk(kup,temp,boyut,4,move);
					paste_fonk_col_ters(kup,temp2,boyut,3,move);						
				}
			}
			else if(strcmp(bolge,"column")==0 && face==4){	//4.yüzde satiri asagi yukari kaydirma

				if(strcmp(yon,"up")==0){
					copy_fonk_col_ters(kup,temp,boyut,face,move);				
					copy_fonk_col_reverse(kup,temp2,boyut,2,move);	
					paste_fonk_col_reverse(kup,temp,boyut,2,move);					
					copy_fonk_col(kup,temp,boyut,5,move);
					paste_fonk_col_ters(kup,temp2,boyut,5,move);	
					copy_fonk_col(kup,temp2,boyut,0,move);		
					paste_fonk_col(kup,temp,boyut,0,move);
					paste_fonk_col(kup,temp2,boyut,4,move);							
				}

				else if(strcmp(yon,"down")==0){
					copy_fonk_col(kup,temp,boyut,face,move);						
					copy_fonk_col(kup,temp2,boyut,0,move);	
					paste_fonk_col(kup,temp,boyut,0,move);					
					copy_fonk_col(kup,temp,boyut,5,move);
					paste_fonk_col(kup,temp2,boyut,5,move);	
					copy_fonk_col_reverse(kup,temp2,boyut,2,move);		
					paste_fonk_col_reverse_ters(kup,temp,boyut,2,move);
					paste_fonk_col_ters(kup,temp2,boyut,4,move);					
				}				
			}
			else if(strcmp(bolge,"column")==0 && face==5){	//5.yüzde satiri asagi yukari kaydirma
				if(strcmp(yon,"up")==0){
					copy_fonk_col(kup,temp,boyut,face,move);			
					copy_fonk_col(kup,temp2,boyut,0,move);	
					paste_fonk_col(kup,temp,boyut,0,move);					
					copy_fonk_col_ters(kup,temp,boyut,4,move);
					paste_fonk_col(kup,temp2,boyut,4,move);	
					copy_fonk_col_reverse(kup,temp2,boyut,2,move);		
					paste_fonk_col_reverse(kup,temp,boyut,2,move);
					paste_fonk_col_ters(kup,temp2,boyut,5,move);							
				}
				else if(strcmp(yon,"down")==0){
					copy_fonk_col_ters(kup,temp,boyut,face,move);			
					copy_fonk_col_reverse(kup,temp2,boyut,2,move);	
					paste_fonk_col_reverse(kup,temp,boyut,2,move);					
					copy_fonk_col(kup,temp,boyut,4,move);
					paste_fonk_col_ters(kup,temp2,boyut,4,move);	
					copy_fonk_col(kup,temp2,boyut,0,move);		
					paste_fonk_col(kup,temp,boyut,0,move);
					paste_fonk_col(kup,temp2,boyut,5,move);					
				}
			}									
																									
		}	
			
	}
	fp2=fopen("result.txt","w");
	for(i=0;i<6;i++){       /*yuzler uzerinde yaptigim islem sonucunu yeni bir dosyaya bastirdim*/
		for(column=0;column<boyut;column++){	
			for(t=0;t<boyut;t++){
				fprintf(fp2,"%d",kup[i].array[column][t]);
			}
			fprintf(fp2,"%c",'\n');
		}
		fprintf(fp2,"%c",'\n');

	}
	fclose(fp1);    /*okudugum dosyayi kapadim*/
	fclose(fp2);    /*yazma islemi yaptigim dosyayi kapadim*/
	for(t=boyut-1,i=5;t>=0;t--,i--){    /*yer alarak islem yaptigim arrayi yer alma islemimin tersi yonunde bosalttim*/
		free(kup[i].array[t]);
	}
	for(i=5;i>=0;i--){
		free(kup[i].array);
	}

	
}
void copy_fonk(rubic* kup,int array[],int boyut,int yuz,int koor){  /*bir satirdaki belli koordinati kopyaladim*/
	int i;
	for(i=0;i<boyut;i++){
		array[i]=kup[yuz].array[koor][i];	
	}
}

void copy_fonk_ters(rubic* kup,int array[],int boyut,int yuz,int koor){ /*bir satirdaki belli koordinati tersten kopyaladim*/
	int i;
	int a=0;
	for(i=boyut-1;i>=0;i--){
		array[a]=kup[yuz].array[koor][i];	
		a++;
	}
}

void copy_fonk_col(rubic* kup,int array[],int boyut,int yuz,int koor){  /*bir sütundaki belli koordinati kopyaladim*/
	int i;
	for(i=0;i<boyut;i++){
		array[i]=kup[yuz].array[i][koor];	
	}
}

void copy_fonk_col_ters(rubic* kup,int array[],int boyut,int yuz,int koor){ /*bir sütundaki belli koordinati tersten kopyaladim*/
	int i;
	int a=0;
	for(i=boyut-1;i>=0;i--){
		array[a]=kup[yuz].array[i][koor];	
		a++;
	}
}

void paste_fonk(rubic* kup,int array[],int boyut,int yuz,int koor){     /*onceden kaydettigim satiri kupte yapistirdim*/
	int i;
	for(i=0;i<boyut;i++){
		kup[yuz].array[koor][i]=array[i];
	}
}

void paste_fonk_col_ters(rubic* kup,int array[],int boyut,int yuz,int koor){       /*onceden kaydettigim sutunu ters sekilde kupte yapistirdim*/
	int i;
	int a=0;
	for(i=boyut-1;i>=0;i--){
		kup[yuz].array[a][koor]=array[i];
		a++;
	}
}

void paste_fonk_ters(rubic* kup,int array[],int boyut,int yuz,int koor){    /*onceden kaydettigim satiri kupte tersten yapistirdim*/
	int i;
	int a=0;
	for(i=boyut-1;i>=0;i--){
		kup[yuz].array[koor][a]=array[i];
		a++;
	}
}

void paste_fonk_col(rubic* kup,int array[],int boyut,int yuz,int koor){     /*onceden kaydettigimi kupte sutuna yapistirdim*/
	int i;
	for(i=0;i<boyut;i++){
		kup[yuz].array[i][koor]=array[i];
	}
}
void copy_fonk_reverse(rubic* kup,int array[],int boyut,int yuz,int koor){      /*kupten sondan baslamak uzere ters satirdan kopyaladim*/
	int i;
	for(i=0;i<boyut;i++){
		array[i]=kup[yuz].array[boyut-koor-1][i];	//koor- move
	}
}

void paste_fonk_reverse(rubic* kup,int array[],int boyut,int yuz,int koor){     /*kupte ters satira yapistirma islemi yaptim*/
	int i;
	for(i=0;i<boyut;i++){
		kup[yuz].array[boyut-koor-1][i]=array[i];
	}
}

void copy_fonk_col_reverse(rubic* kup,int array[],int boyut,int yuz,int koor){  /*kupteki sutunu belli koordinatin son sutuna gore kopyaladim*/
	int i;
	for(i=0;i<boyut;i++){
		array[i]=kup[yuz].array[i][boyut-koor-1];	//koor- move
	}
}

void paste_fonk_col_reverse(rubic* kup,int array[],int boyut,int yuz,int koor){    /*kupun ters sutununa gore yapistirma islemi yaptim*/
	int i;
	for(i=0;i<boyut;i++){
		kup[yuz].array[i][boyut-koor-1]=array[i];
	}
}

void paste_fonk_col_reverse_ters(rubic* kup,int array[],int boyut,int yuz,int koor){    /*onceden kopyaladigim sutunu tersten son sutuna dayali olarak yapistirdim*/
	int i;
	int a=0;
	for(i=boyut-1;i>=0;i--){
		kup[yuz].array[a][boyut-koor-1]=array[i];
		a++;
	}
}

void paste_fonk_reverse_ters(rubic* kup,int array[],int boyut,int yuz,int koor){        /*onceden kopyaladigim satiri tersten son sutuna dayali olarak yapistirdim*/
	int i;
	int a=0;
	for(i=boyut-1;i>=0;i--){
		kup[yuz].array[boyut-koor-1][a]=array[i];
		a++;
	}
}






