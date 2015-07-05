# this solution passes test cases #1-#3 and fails cases #4-#11 for taking too long
def process(matrix, curse)
  discomfort = 0
  curse.times do
    discomfort += one_curse(matrix)
  end
  discomfort
end

def myprint(matrix)
  puts(", matrix:")
  matrix.size.times do |i|
    matrix.size.times do |j|
      print("#{matrix[i][j]} ")
    end
    puts
  end
end

def one_curse(matrix)
  size = matrix.size
  mini = 0
  row = -1
  size.times do |i|
    sum = 0
    size.times do |j|
      sum += matrix[i][j]
    end
    if mini == 0 || sum < mini
      mini = sum
      row = i
      # puts("mini: #{mini}, row: #{i}")
    end
  end

  minj = 0
  column = -1
  size.times do |j|
    sum = 0
    size.times do |i|
      sum += matrix[i][j]
      # puts("i: #{i}, j: #{j}, matrix[i][j]: #{matrix[i][j]}")
    end
    # puts("sum: #{sum}")
    if minj == 0 || sum < minj
      minj = sum
      column = j
      # puts("minj: #{minj}, column: #{j}")
    end
  end

  if mini <= minj
    size.times do |j|
      matrix[row][j] += 1
    end
    discomfort = mini
    puts("row: #{row}, discomfort: #{mini}")
    # myprint(matrix)
  else
    size.times do |i|
      matrix[i][column] += 1
    end
    discomfort = minj
    puts("column: #{column}, discomfort: #{minj}")
    # myprint(matrix)
  end

  discomfort
end

case_count = gets.to_i
case_count.times do
  numbers = gets.split.map {|i| i.to_i}
  matrix_size = numbers[0]
  curse = numbers[1]
  matrix = []
  matrix_size.times do
    matrix << gets.split.map {|i| i.to_i}
  end
  puts(process(matrix, curse))
end
