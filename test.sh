pathans="./answers"

echo ""

for i in {1..5};do 
    make &>/dev/null all
    echo "------------ Test case $i ------------"
    time ./tserver < ./testcases/input$i.txt
    echo "------------ Diff check -------------"
    echo "(empty = no difference)"
    for i in {1..170000}; do
        if [ -f "./${i}t.out" ]; then
            diff -q ./${i}t.out ./answers/${i}s.out
        fi
    done
    echo ""
    make &>/dev/null clean
done


# for i in {1..170000}; do
#     if [ -f "./${i}t.out" ]; then
#         diff -q ./${i}t.out ./answers/${i}s.out
#     fi
#     if [ -f "./${i}p.out" ]; then
#         diff -q ./${i}p.out ./answers/${i}s.out
#     fi
# done

echo "-------------------------------------"

make clean
