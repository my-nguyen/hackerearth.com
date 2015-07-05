def process(string, query)
  records = []
  current = 0
  while current < string.length
    debut = string.length
    fin = 0
    tmp = query.dup
    tmp.each_char do |char|
      if !(index = string[current..-1].index(char)).nil?
        index += current
        debut = index if index < debut
        fin = index if index > fin
        #puts("begin: #{debut}, end: #{fin}, query: #{query}, char: #{char}, index: #{index}")
        tmp.slice!(0)
      end
    end
    current = debut + 1
    if tmp.empty?
      #puts("string: #{string}, query: #{query}, begin: #{debut}, end: #{fin}, substring: #{string[debut..fin]}")
      records << [string[debut..fin], debut]
    end
  end
  print records
  puts

  count = 0
  records.each do |record|
    left = record[1] - 0
    right = string.length - (record[1] + record[0].length)
    count += 
  end
  return left
end

case_count = gets.to_i
case_count.times do
  string = gets.chomp
  query_count = gets.to_i
  query_count.times do
    puts process(string, gets.chomp)
  end
end
