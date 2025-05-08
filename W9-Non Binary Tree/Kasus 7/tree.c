#include <stdio.h>
#include "tree.h"

nbtree nb (infotype info, address fs, address nb, address pr){
    nbtree temp;
    temp.info = info;
    temp.ps_fs = fs;
    temp.ps_nb = nb;
    temp.ps_pr = pr;
    return temp;
}

void Create_tree(Isi_Tree X, int Jml_Node){
    if (Jml_Node < 0 || Jml_Node > jml_maks){
        printf("Create tree gagal karena kesalahan input\n");
        return;
    }

    int i = 1;
    while (i <= Jml_Node){
        X[i].info = 0;
        X[i].ps_fs = 0;
        X[i].ps_nb = 0;
        X[i].ps_pr = 0;
        i++;
    }
}

bool IsEmpty(Isi_Tree P) {
    return (P[1].info == 0);
}

void PreOrder (Isi_Tree P, address curr){ //current,fs,nb
    PreOrderRec (P,curr);
}

void PreOrderRec (Isi_Tree P, address curr) {
    if (curr == 0 || P[curr].info == 0) {
        return;
    }
    
    // Visit current
    printf("%c ", P[curr].info);
    
    //first child
    PreOrderRec(P, P[curr].ps_fs);
    
    //next sibling
    PreOrderRec(P, P[curr].ps_nb);
}

void PostOrder (Isi_Tree P, address curr){ //fs, current, nb
    PostOrderRec (P,curr);
}

void PostOrderRec (Isi_Tree P, address curr){
    if (curr == 0 || P[curr].info == 0) {
        return;
    }

    PostOrderRec (P, P[curr].ps_fs);

    printf ("%c", P[curr].info);

    PostOrderRec (P, P[curr].ps_nb);
}

void InOrder (Isi_Tree P, address curr){ 
    //fs, current, current(exist nb), nb
    InOrderRec (P,curr);
}

void InOrderRec (Isi_Tree P, address curr){
    if (curr == 0 || P[curr].info == 0) {
        return;
    }

    InOrderRec (P, P[curr].ps_fs);

    printf ("%c", P[curr].info);

    if (P[curr].ps_fs!=0){
        address brother;
        brother=P[P[curr].ps_fs].ps_nb;
        while (brother != 0){
            InOrderRec (P, brother);
            brother=P[brother].ps_nb;
        }
    }
}

void Level_order(Isi_Tree X, int Maks_node) {
    if (IsEmpty(X)) {
        return;
    }

    address queue[jml_maks + 1];
    bool visited[jml_maks + 1];
    for (int i = 0; i <= jml_maks; i++) visited[i] = false;
    int front = 0;
    int rear = 0;

    // Enqueue root
    queue[rear++] = 1;
    visited[1] = true;

    while (front < rear) {
        address current = queue[front++];
        printf("%c ", X[current].info);

        // Enqueue all children
        if (X[current].ps_fs != 0) {
            address child = X[current].ps_fs;
            while (child != 0 && child <= Maks_node) {
                if (!visited[child]) {
                    queue[rear++] = child;
                    visited[child] = true;
                }
                child = X[child].ps_nb;
            }
        }
    }
}


//Generate Graphviz
void PrintTree(Isi_Tree P, const char* filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("error opening file\n");
        return;
    }

    fprintf(fp, "digraph NonBinaryTree {\n");
    if (IsEmpty(P)) {
        fprintf(fp, "  empty;\n");
    } else {
        for (int i = 1; i <= jml_maks; i++) {
            if (P[i].info != 0) {
                address child = P[i].ps_fs;
                while (child != 0) {
                    fprintf(fp, "  %c -> %c;\n", P[i].info, P[child].info);
                    child = P[child].ps_nb;
                }
            }
        }
    }
    fprintf(fp, "}\n");
    fclose(fp);

    printf("graph generated in %s\n", filename);
    printf("you can visit this link if you want to see output\n");
    printf("https://dreampuf.github.io/GraphvizOnline/\n");
    printf("or run this in cmd 'dot -Tpng tree.dot -o tree.png'\n");
}

bool Search (Isi_Tree P, infotype X) {
    return SearchRec (P, X, 1);
}

bool SearchRec(Isi_Tree P, infotype X, address curr) {
    if (curr == 0 || P[curr].info == 0) {
        return false;
    }
    
    if (P[curr].info == X) {
        return true;
    }
    
    if (SearchRec(P, X, P[curr].ps_fs)) {
        return true;
    }
    
    if (SearchRec(P, X, P[curr].ps_nb)) {
        return true;
    }
    
    return false;
}

int nbElmt (Isi_Tree P){
    int count=0, i=1;

    while (i<jml_maks){
        if (P[i].info!=0){
            count++;
        }
        i++;
    }
    return count;
    
    // int nbElmtRec(Isi_Tree P, address curr) {
    //     if (curr == 0 || P[curr].info == 0) {
    //         return 0;
    //     }
        
    //     // Count current node (1) + all nodes in first child subtree + all nodes in next sibling subtree
    //     return 1 + nbElmtRec(P, P[curr].ps_fs) + nbElmtRec(P, P[curr].ps_nb);
    // }
}

int nbDaun(Isi_Tree P) {
    int count = 0;
    for (int i = 1; i <= jml_maks; i++) {
        if (P[i].info != 0 && P[i].ps_fs == 0) {
            count++;
        }
    }
    return count;

    // int nbDaunRec(Isi_Tree P, address curr) {
    //     if (curr == 0 || P[curr].info == 0) {
    //         return 0;
    //     }
        
    //     // no fs=leaf
    //     if (P[curr].ps_fs == 0) {
    //         return 1;
    //     }
        
    //     return nbDaunRec(P, P[curr].ps_fs) + nbDaunRec(P, P[curr].ps_nb);
    // }
}

int Level(Isi_Tree P, infotype X) {
    if (IsEmpty(P)) return -1;  
    return LevelRec(P, X, 1, 0);
}

int LevelRec(Isi_Tree P, infotype X, address curr, int currLevel) {
    // empty
    if (curr == 0 || P[curr].info == 0) {
        return -1;  // not found
    }
    
    if (P[curr].info == X) {
        return currLevel;
    }
    
    // fs
    int levelInChild = LevelRec(P, X, P[curr].ps_fs, currLevel + 1);
    if (levelInChild != -1) {
        return levelInChild;
    }
    
    // nb
    return LevelRec(P, X, P[curr].ps_nb, currLevel);
}

int Depth (Isi_Tree P){
    if (IsEmpty (P)) return -1;
    return DepthRec(P,1);
}

int DepthRec(Isi_Tree P, address curr) {
    if (curr == 0 || P[curr].info == 0) {
        return -1;
    }

    int maxChildDepth = -1;
    address child = P[curr].ps_fs;
    while (child != 0) {
        int childDepth = DepthRec(P, child);
        if (childDepth > maxChildDepth) {
            maxChildDepth = childDepth;
        }
        child = P[child].ps_nb;
    }

    return maxChildDepth + 1;
}

int Max(infotype Data1, infotype Data2){
	return (int) ((Data1 > Data2) ? Data1 : Data2);
}

void initialize_tree(Isi_Tree tree) {
    tree[1] = nb('A', 2, 0, 0);
    tree[2] = nb('B', 4, 3, 1);
    tree[3] = nb('C', 6, 0, 1);
    tree[4] = nb('D', 0, 5, 2);
    tree[5] = nb('E', 9, 0, 2);
    tree[6] = nb('F', 0, 7, 3);
    tree[7] = nb('G', 0, 8, 3);
    tree[8] = nb('H', 0, 0, 3);
    tree[9] = nb('I', 0, 10, 5);
    tree[10] = nb('J', 0, 0, 5);
}