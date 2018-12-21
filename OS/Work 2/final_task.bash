# len=`cat errors.log | wc -l`
# len=$(( $len + 1 ))
# l=$(( $len - 10 ))
# sed -n "${l},${len}p" "errors.log"

len=`cat errors.log | wc -l`
len=$(( $len + 1 ))
l=$(( $len - 10 ))
sed -n "${l},${len}p" "errors.log"