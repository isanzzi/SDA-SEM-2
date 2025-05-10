#include "tree.h"

address Create_node (infotype info){
	address temp = (address) malloc (sizeof(nbtree));
	if (!isEmpty(temp)){
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

//Generate Graphviz
void PrintTree(address P, const char* filenameinput, const char* filenameoutput) {
    FILE *fp = fopen(filenameinput, "r");
    FILE *fr = fopen(filenameoutput, "w");
    if (fp == NULL) {
        printf("error acces input.txt\n");
        return;
    }
    if (fr == NULL) {
        printf ("error acces output.txt\n");
        return;
    }
    

    fprintf(fp, "digraph NonBinaryTree {\n");
    if (IsEmpty(P)) {
        fprintf(fp, "  empty;\n");
    } else {
        int i=1;
        while (i<=jml_maks) {
            if (P[i].info != 0) {
                address child = P[i].ps_fs;
                while (child != 0 && child <=jml_maks) {
                    if (P[child].info != 0){
                    fprintf(fp, "  %c -> %c;\n", P[i].info, P[child].info);
                    }
                    child = P[child].ps_nb;
                }
            }
            i++;
        }
    }
    fprintf(fp, "}\n");
    fclose(fp);
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

void convertstring (address P, char *str){
    int i=0;
    while (str[i]!='\0'){ // selama belum enter
        if (str[i]== ' '){
            printf("  "); //space antar kata
            continue;
        }
        char temp= toupper(str[i]);
        getMorseCode (P, temp);
        printf(" "); //between char
        i++;
    }
    printf ("\n");
}

void getMorseCode (address P, char target){
    if (IsEmpty (P)){
        return;
    }
}

void printMorseCode (address P, char target){
    if ()
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
    Y->right=0;
    satu->right=lima;
    dua->right=empat;
    lima->right=sembilan;
    enam->right=delapan;
    sembilan->right=space;
}