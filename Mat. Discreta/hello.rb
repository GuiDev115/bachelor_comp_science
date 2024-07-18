# Adendo, usar o compiler online pode dar resultado falso, certifique que compile mais de uma vez.
# caso use proprio compilador do MinGW, nao há sequer algum erro

=begin
  Nome: Guilherme Fabricio Brito da Rosa
  Turma: 10A
  GMM135-2022

  Exercicio R6 - Ruby sobre contar sequencias
=end


# Variaveis já com valores iniciais
x = 7
y = -1
z = -1

# Valor do total para ser 5
total = x + y + z

# Utilizacao de variaveis auxiliares e contadores
contador = 0
aux = 1

puts "As sequencias são: " 

while z < 7 do

    while x >= 0 do
        contador = contador + 1; 

        # Resultado de cada operacao
        puts "#{x} #{y} #{z}"

        x = x-1
        y = y+1
    end

    puts "\n"

    z = z+1;
    x = 7 - aux
    y = -1
    aux = aux + 1

end

# Resultado total de sequencias que o exercicio pediu
puts "\nTotal de: #{contador} sequencias" 