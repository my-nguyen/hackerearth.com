def process string
  result = ""
  current = ' '
  string.each_char do |char|
    if char != current
      result << char
      current = char
    end
  end
  return result
end

gets.to_i.times do
  puts process(gets.chomp)
end
