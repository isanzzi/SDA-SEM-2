#include "tree.h"

address Create_node (infotype info){
	address temp = (address) malloc (sizeof(nbtree));
	if (!IsEmpty(temp)){
		temp->info = info;
		temp->left = NULL;
		temp->right = NULL;
		temp->parent = NULL;
	} else {
        printf ("gagal membuat node\n");
    }
	return temp;
}

void Create_tree(address *root){
	*root=NULL;
}

bool IsEmpty(address P) {
    if (P==NULL){
    	return true;
	} else {
		return false;
	}
}

void InOrder (address P){ 
    if(IsEmpty(P)){
        return;
    }

    //fs, current, current(exist nb), nb
    InOrder (P->left);
    printf ("%c", P->info);
    InOrder (P->right);
}

void ClearTree (address *root){
    if (root== NULL){
        printf ("no tree\n");
    }

    if ((*root)->left != NULL){
        address temp = (*root)->left;
        (*root)->left = NULL;
        ClearTree (&temp);
    }

    if ((*root)->right != NULL){
        address temp = (*root)->right;
        (*root)->right = NULL;
        ClearTree (&temp);
    }

    free (*root);
    *root = NULL;
}

// void convertstring (address P, char *str){
//     int i=0;
//     while (str[i]!='\0'){ // selama belum enter
//         if (str[i]== ' '){
//             printf("/"); //space antar kata
//             continue;
//         }
//         char temp= toupper(str);
//         printf(" "); //between char
//         i++;
//     }
//     printf ("\n");
// }

void txtstringtomorse (address head){
    FILE *fr = fopen ("input.txt", "r");
    FILE *fw = fopen ("output.txt", "w");
    if (fr == NULL || fw == NULL){
        printf ("error opening file\n");
        return;
    }
    char buffer [1000]= {0};
    int index=0;
    int c;
    
    while ((c = fgetc(fr)) != EOF && index < 1000) {
        buffer [index++] = (char) c;
    }
    buffer [index]= '\0';

    toupperstring (buffer);

    char output[2000] = {0};

    stringtomorse (head, head, buffer, output);

    fprintf(fw, "%s", output);
    printf ("konversi input.txt to ouput.txt success\n");
    fclose(fr);
    fclose(fw);
}

void stringtomorse(address root, address p, char *str, char *hasil) {
    if (*str == '\0') {
        return;
    }
    if (*str == ' ') {
        if (p != NULL) {
            int len = (int) strlen (hasil);
            hasil[len]=p->info;
            hasil [len+1]= '\0';
        }
        stringtomorse(root, root, str + 1, hasil); // reset
    }
    else if (*str == '/') {
        int len = (int) strlen (hasil);
        hasil[len]=' ';
        hasil[len+1]='\0';
        hasil=" ";
        stringtomorse(root, root, str + 1, hasil); // reset
    }
    else if (*str == 'r') {
        if (p != NULL) {
            stringtomorse(root, p->left, str + 1, hasil);
        } else {
            stringtomorse(root, NULL, str + 1, hasil);
        }
    }
    else if (*str == 'n') {
        if (p != NULL) {
            stringtomorse(root, p->right, str + 1, hasil);
        } else {
            stringtomorse(root, NULL, str + 1, hasil);
        }
    }
    else {
        stringtomorse(root, p, str + 1, hasil); //erorr e
    }
}

void toupperstring (char *str){
    int i=0;
    while (str[i]!= '\0'){
        str[i] = (char)toupper((unsigned char)str[i]);
        i++;
    }
}

void initialize_tree(address *root) {
    *root = Create_node (0);
    address A = Create_node('A');
    address B = Create_node('B');
    address C = Create_node('C');
    address D = Create_node('D');
    address E = Create_node('E');
    address F = Create_node('F');
    address G = Create_node('G');
    address H = Create_node('H');
    address I = Create_node('I');
    address J = Create_node('J');
    address K = Create_node('K');
    address L = Create_node('L');
    address M = Create_node('M');
    address N = Create_node('N');
    address O = Create_node('O');
    address P = Create_node('P');
    address Q = Create_node('Q');
    address R = Create_node('R');
    address S = Create_node('S');
    address T = Create_node('T');
    address U = Create_node('U');
    address V = Create_node('V');
    address W = Create_node('W');
    address X = Create_node('X');
    address Y = Create_node('Y');
    address Z = Create_node('Z');
    
    address nol = Create_node('0');
    address satu = Create_node('1');
    address dua = Create_node('2');
    address tiga = Create_node('3');
    address empat = Create_node('4');
    address lima = Create_node('5');
    address enam = Create_node('6');
    address tujuh = Create_node('7');
    address delapan = Create_node('8');
    address sembilan = Create_node('9');
    
    address space = Create_node(' ');

    (*root)->left = A;
    (*root)->right = B;
    
    A->left=B;
    B->left=C;
    C->left=D;
    D->left=E;
    G->left=H;
    J->left=K;
    M->left=N;
    N->left=O;
    Q->left=R;
    T->left=U;
    U->left=V;
    V->left=W;
    Y->left=Z;
    satu->left=dua;
    dua->left=tiga;
    lima->left=enam;
    enam->left=tujuh;

    A->right=M;
    B->right=J;
    C->right=G;
    D->right=F;
    G->right=I;
    J->right=L;
    M->right=Q;
    N->right=P;
    Q->right=S;
    T->right=satu;
    U->right=Y;
    V->right=X;
    Y->right=nol;
    satu->right=lima;
    dua->right=empat;
    lima->right=sembilan;
    enam->right=delapan;
    sembilan->right=space;
}