
# Generate random strings
python -c "import randoml, string;\
f=open('assets/big_strings.txt','w');\
[ f.write(''.join(random.choices(string.ascii_letters+string.digits,k=16)) + '\n') for _ in range(1000000) ]; f.close()"


# Generate random floats
python -c "import random;
with open('assets/big_float_numbers.txt','w') as f:
    for _ in range(1_000_000):
        val = ((-1 if random.randint(0,1) else 1) * random.random() * 10**5)
        f.write(f'{val:.4f}\n')"

# Generate random int
python -c "import random; f=open('assets/big_int_numbers.txt','w'); \
[ f.write(str((-1)**random.randint(0,1) * random.randint(1,10**7)) + '\n') for _ in range(1000000) ]; \
f.close()"

# Generate random long int
python -c "import random; f=open('assets/big_long_numbers.txt','w'); \
[f.write(str((-1)**random.randint(0,1) * random.randint(1,10**13)) + '\n') for _ in range(1000000) ]; \
f.close()"