def find_divisors(number)
  divisors = [1]
  2.upto(number/2) do |i|
    #puts("number: #{number}, i: #{i}")
    if (number % i == 0)
      divisors << i
    end
  end
  divisors << number
  #puts(divisors.inspect)
  divisors
end

def find_gcd(numbers)
  gcd = [1]
end

count = gets.to_i
numbers = gets.split.map {|i| i.to_i}
