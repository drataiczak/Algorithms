rand_max = 10
rand_min = 0
array_size = 10

function sort(array)
  -- # is the length operator
  for i = 0, #array do
    for j = i + 1, #array do
      if array[i] > array[j] then
        temp = array[i]

        array[i] = array[j]
        array[j] = temp
      end
    end
  end
end

function main()
  local array = {}

  io.write("The original array is: [ ")
  for i = 0, array_size - 1 do
    array[i] = math.random(rand_min, rand_max) % (rand_max - rand_min + 1) + rand_min
    
    if i == (array_size - 1) then
      print(string.format("%d ]", array[i]))
    else
      io.write(string.format("%d, ", array[i]))
    end
  end

  sort(array)

  io.write("The sorted array is: [ ")
  for i = 0, array_size - 1 do
    if i == (array_size - 1) then
      print(string.format("%d ]", array[i]))
    else
      io.write(string.format("%d, ", array[i]))
    end
  end
end

main()
