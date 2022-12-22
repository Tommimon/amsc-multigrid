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
x = [16, 32, 64, 128, 'Initial grid size', 'Number of iterations']
y = [368, 1797, 8394, 38287, 'Jacobi']
y2 = [186, 901, 4200, 19147, 'Gauss']

save_dots(x, y, y2, 'Serial solvers comparison')
