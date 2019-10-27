make --silent
for i in {0..2}
do
    ./fillit "tests/test_0$i" > res
    diff "res" "results/res_0$i" >> difference
    rm res
done
cat difference
rm difference 