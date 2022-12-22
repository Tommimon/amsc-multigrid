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
x = [16, 32, 64, 128, 'Initial grid size', 'Execution time']
y = [0.006, 0.089, 1.522, 7.539, 'Without multi-grid']
y2 = [0.010, 0.027, 0.066, 0.436, 'With multi-grid']

save_dots(x, y, y2, 'Jacobi solver with and without Multi-grid comparison')
