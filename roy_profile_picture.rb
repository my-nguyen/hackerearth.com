def process(dimension, length)
  if (dimension[0] < length || dimension[1] < length)
    return "UPLOAD ANOTHER"
  elsif (dimension[0] == dimension[1])
    return "ACCEPTED"
  else
    return "CROP IT"
  end
end

length = gets.to_i
gets.to_i.times do
  puts(process(gets.scan(/\d+/).map(&:to_i), length))
end
