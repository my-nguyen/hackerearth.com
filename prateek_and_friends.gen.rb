cases = rand(1..10)
puts cases
cases.times do
  friends = rand(1..(10**2))
  max = rand(1..(10**4))
  puts("#{friends} #{max}")
  friends.times do
    cost = rand(1..(10**2))
    puts cost
  end
end
