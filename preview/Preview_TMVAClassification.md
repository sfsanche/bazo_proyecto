#Learning about some important objects in program TMVAClassification.C

1. std::map<std::string,int> Use; // Un arreglo de dos variables asociativas, relaciona string(e.g. perro) con un int(e.g. 1), asi podemos llamar en vez de a uno, a perro. Use es el nombre del map que se declara, es decir que la primera entrada string es un entero.
2. There are other part for use methods that we had choose.
3. Create root file.
4. Create Fatory with string of configuration. !V!Silent: show some but not all.
                                            Transformation, the code is prove all transformations preview for identify correlations PCA.
5. Then we add ours variables (Wlep, calresp0, Ev, x, y, t)
6. The spectator were El and nf.
7. We put our archive of data.
8. We put the url of github, which the data is.
9. Register the training and test tree. We have both signal and background in the same ttree, identified by the cuts: Tcut singnalCut="nmuons==2"; and Tcut backgrCut="nmuons<2";
10. In our case; we leave to use the weights ecause our evets have all uniform weights.
11. Aout other cuts we maybe put other motived by papers.
12. In part about factory we prepare training and test events. In our case, leave nTrain_Signal=0 use all; and nTrain_background=0 Separate all the avaliable events half randomly 
