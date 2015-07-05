def factorial(n)
  product = 1
  1.upto(n) do |i|
    product *= i
  end
  product
end

gets.to_i.times do
  puts factorial(gets.to_i)
end
