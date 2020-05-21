# AbstractSyntaxTree
## 04-visitors

## bin
Contains two examples of Mini-Java-programs and the AST representations for these programs. Program
```
interpreter_example.txt
```
can also be successfully interpreted, for this you will need to run:
```
cd bin
./ASTreeVisitor interpreter_example.txt
```
## graphviz
For drawing AST representation you will need graphviz.
```
sudo apt install graphviz
```
To draw with graphviz use:
```
dot -Tpng ASTree.txt -o output_file.txt
```
where ```input_file.txt``` is created by the 
```
./ASTreeVisitor
```
