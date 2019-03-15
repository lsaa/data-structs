#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>

#include "nodes.h"
#include "binary_tree.h"

std::string a, dmp;
int n, i, casos;
BSTnode<int>* tmp;

using namespace std;

int main (void) {
	casos = 0;
	string cmds;
	while (scanf("%d", &n) != EOF) {
        getline(cin, dmp);
		casos++;
		BST<int> arv;
		printf("Caso %d:\n", casos);
		for (int j = 0; j < n; j++) {
            getline(cin, cmds);

            if (cmds == "PRE") {
				if (arv.root == NULL)
					printf("0");
				else 
                	arv.preorder();
                printf("\n");
            } else if (cmds == "IN") {
				if (arv.root == NULL)
					printf("0");
				else 
                	arv.inorder();
                printf("\n");
            } else if (cmds == "POST") {
				if (arv.root == NULL)
					printf("0");
				else 
                	arv.postorder();
                printf("\n");
            } else {
                stringstream s(cmds);
                s >> a >> i;
                if (a == "A") {
                    arv.insert(i);
                } else if (a == "B") {
                    arv.remove(arv.search(i));
                } else {
                    int tmpi = arv.minAt(i);
                    printf("%d\n", tmpi);
                }
            }
        }
	}
}
