# import module
import matplotlib.pyplot as plt


def save_dots(x_list, y_list, y2_list=None, name='Test'):
    # set the title of a plot
    plt.title(name)

    # plot scatter plot with x and y data
    plt.scatter(x_list[:-2], y_list[:-1])
    if y2_list is not None:
        plt.scatter(x_list[:-2], y2_list[:-1])

    # plot with x and y data
    plt.plot(x_list[:-2], y_list[:-1], label=y_list[-1])
    if y2_list is not None:
        plt.plot(x_list[:-2], y2_list[:-1], label=y2_list[-1])

    plt.xlabel(x[-2])
    plt.ylabel(x[-1])
    plt.legend()

    plt.savefig('assets/' + name.lower() + '.png')


# initialize x and y coordinates
x = [32, 64, 128, 256, 512, 1024, 2048, 'Initial grid size', 'Execution time']
y = [0.005, 0.017, 0.066, 0.258, 1.079, 4.720, 17.857, 'Serial']
y2 = [0.026, 0.058, 0.143, 0.388, 0.918, 2.536, 10.753, 'Parallel']

save_dots(x, y, y2, 'Serial and Parallel Sor comparison')
