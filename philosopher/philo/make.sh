i=1
j=0
max=15000
sp="/-\|"
printf "\033[;33mLoading...  \033[0m" 
while [ $j -lt $max ]
do
    printf "\b\033[;33m${sp:i++%${#sp}:1}"
    j=$(($j+1))
done
printf "\b\033[;33mdone.\n\033[0m"
printf "\b\033[;32\nmmake success \b ✅\n\033[0m"
printf "\b\033[;37m\n\033[0m"