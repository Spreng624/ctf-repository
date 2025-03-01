import java.util.Base64;
import java.util.Arrays;

public class justsoso {
    private static int[] initial(int[] iArr) {
        int length = iArr.length;
        int[] iArr2 = new int[256];
        int[] iArr3 = new int[256];
        for (int i = 0; i < 256; i++) {
            iArr2[i] = 256 - i;
            iArr3[i] = iArr[i % length];
        }
        int i2 = 0;
        for (int i3 = 0; i3 < 256; i3++) {
            int i4 = iArr2[i3];
            i2 = ((i2 + i4) + iArr3[i3]) % 256;
            int i5 = iArr2[i2];
            iArr2[i2] = i4;
            iArr2[i3] = i5;
        }
        return iArr2;
    }

    public static byte[] encrypt(byte[] bArr, int[] iArr) {
        int length = bArr.length;
        int[] initial = initial(iArr);
        int i = 0;
        int i2 = 0;
        for (int i3 = 0; i3 < length; i3++) {
            i = (i + 1) % 256;
            int i4 = initial[i];
            i2 = (i2 + i4) % 256;
            int i5 = initial[i2];
            initial[i] = i5;
            initial[i2] = i4;
            bArr[i3] = (byte) (bArr[i3] ^ ((byte) initial[(i4 + i5) % 256]));
        }

        System.out.println(Arrays.toString(initial));
        System.out.println(i);
        System.out.println(i2);
        return bArr;
    }

    public static byte[] decrypt(byte[] bArr, int[] iArr) {
        int length = bArr.length;
        int[] initial = { 107, 11, 190, 182, 97, 252, 84, 71, 59, 218, 18, 68, 241, 141, 155, 240, 170, 78, 43, 175, 98,
                87, 239, 53, 228, 81, 157, 44, 13, 26, 158, 179, 79, 210, 234, 251, 163, 249, 130, 120, 211, 219, 129,
                186, 69, 225, 41, 91, 36, 15, 171, 123, 243, 140, 138, 32, 173, 166, 159, 253, 236, 200, 176, 152, 113,
                57, 94, 208, 116, 144, 8, 119, 99, 23, 104, 181, 52, 196, 162, 49, 224, 213, 143, 5, 192, 46, 118, 75,
                114, 136, 160, 178, 205, 149, 65, 29, 20, 102, 223, 148, 39, 115, 124, 127, 229, 255, 122, 50, 117, 83,
                109, 216, 17, 88, 128, 106, 125, 60, 188, 61, 244, 95, 73, 66, 195, 82, 27, 28, 147, 62, 189, 154, 185,
                112, 30, 235, 86, 9, 139, 153, 22, 24, 237, 14, 54, 203, 164, 48, 16, 204, 230, 232, 156, 3, 133, 214,
                74, 161, 70, 220, 238, 47, 183, 10, 2, 180, 131, 169, 67, 58, 1, 250, 254, 6, 207, 199, 198, 42, 247,
                33, 221, 110, 184, 34, 25, 31, 217, 168, 137, 222, 146, 72, 89, 193, 103, 92, 256, 4, 209, 45, 226, 194,
                202, 37, 172, 77, 177, 90, 100, 80, 174, 12, 55, 19, 197, 245, 231, 40, 51, 93, 212, 151, 96, 227, 201,
                121, 108, 126, 21, 63, 35, 165, 7, 145, 56, 111, 187, 38, 105, 150, 85, 242, 132, 134, 142, 64, 233,
                206, 135, 246, 167, 101, 215, 191, 76, 248 };
        int i = 44;
        int i2 = 12;
        for (int i3 = length - 1; i3 >= 0; i3--) {
            int i4 = initial[i2];
            int i5 = initial[i];
            bArr[i3] = (byte) (bArr[i3] ^ ((byte) initial[(i4 + i5) % 256]));
            initial[i2] = i5;
            i2 = (i2 - i4 + 256) % 256;
            initial[i] = i4;
            i = (i + 255) % 256;
        }

        return bArr;
    }

    public static int[] getKey() {
        String source = "just_0xGame_so";
        int[] key = new int[14];
        for (int i = 0; i < source.length(); i++)
            key[i] = 2 * (int) source.charAt(i) ^ 0x7F;

        return key;
    }

    public static void main(String[] args) {
        String encryptedFLAG = "nB9RCjwReif5P1H1MYO6m/hucCGjI6EE9wWEx/E4N+bO5k5ior6MnqAGQfc=";
        String testFlag = "0xGame{111111111111111111111111111111111111}";
        int[] key = getKey();
        encrypt(testFlag.getBytes(), key);

        String FLAG = new String(decrypt(Base64.getDecoder().decode(encryptedFLAG), key));
        System.out.println(FLAG); // 0xGame{fd51ce4b-4556-4cf9-9430-67480614e43b}
    }
}
