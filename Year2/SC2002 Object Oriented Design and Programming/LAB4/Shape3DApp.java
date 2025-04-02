import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Shape3DApp {
    public interface Shape {
        double calculateSurfaceArea(); 
    }

    public static class Sphere implements Shape {
        private double radius;

        public Sphere(double radius) {
            this.radius = radius;
        }

        @Override
        public double calculateSurfaceArea() {
            return 4 * Math.PI * radius * radius;
        }
    }

    public static class Cone implements Shape {
        private double radius;
        private double height;

        public Cone(double radius, double height) {
            this.radius = radius;
            this.height = height;
        }

        @Override
        public double calculateSurfaceArea() {
            return Math.PI * radius * (radius + Math.sqrt(height * height + radius * radius));
        }
    }

    public static class Cuboid implements Shape {
        private double length;
        private double breadth;
        private double height;

        public Cuboid(double length, double breadth, double height) {
            this.length = length;
            this.breadth = breadth;
            this.height = height;
        }

        @Override
        public double calculateSurfaceArea() {
            return 2 * (length * breadth + breadth * height + height * length);
        }
    }

    public static class Cylinder implements Shape {
        private double radius;
        private double height;

        public Cylinder(double radius, double height) {
            this.radius = radius;
            this.height = height;
        }

        @Override
        public double calculateSurfaceArea() {
            return 2 * Math.PI * radius * (radius + height);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<Shape> shapes = new ArrayList<>();

        System.out.print("Enter the total number of 3D shapes: ");
        int numberOfShapes = scanner.nextInt();

        for (int i = 0; i < numberOfShapes; i++) {
            System.out.print("Choose a shape (1: Sphere, 2: Cone, 3: Cylinder, 4: Cuboid): ");
            int choice = scanner.nextInt();
            switch (choice) {
                case 1: // Sphere
                    System.out.print("Enter radius: ");
                    double radius = scanner.nextDouble();
                    shapes.add(new Sphere(radius));
                    break;
                case 2: // Cone
                    System.out.print("Enter radius and height: ");
                    double coneRadius = scanner.nextDouble();
                    double height = scanner.nextDouble();
                    shapes.add(new Cone(coneRadius, height));
                    break;
                case 3: // Cylinder
                    System.out.print("Enter radius and height: ");
                    double cylinderRadius = scanner.nextDouble();
                    double cylinderHeight = scanner.nextDouble();
                    shapes.add(new Cylinder(cylinderRadius, cylinderHeight));
                    break;
                case 4: // Cuboid
                    System.out.print("Enter length, breadth and height: ");
                    double length = scanner.nextDouble();
                    double breadth = scanner.nextDouble();
                    double cuboidHeight = scanner.nextDouble();
                    shapes.add(new Cuboid(length, breadth, cuboidHeight));
                    break;
                default:
                    System.out.println("Invalid choice!");
            }
        }

        double totalSurfaceArea = 0;
        for (Shape shape : shapes) {
            totalSurfaceArea += shape.calculateSurfaceArea();
        }
        System.out.printf("Total surface area of 3D shapes: %.2f%n", totalSurfaceArea);
    }
}

