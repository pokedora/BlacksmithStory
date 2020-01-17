
#include "DxLib.h"


#define GAME_WIDTH 800		//��ʂ̉���
#define GAME_HEIGHT 600		//��ʂ̏c��
#define GAME_COLOR 32		//�g�p�����ʂ̐F�̐�



#define GAME_WINDOW_NAME "GAME_TITLE"
#define GAME_WINDOW_MODECHANGE	TRUE

#define GAME_FPS_SPEED                       60		//FPS��

#define SET_WINDOW_ST_MODE_DEFAULT          0
#define SET_WINDOW_ST_MODE_TITLE_NON        1
#define SET_WINDOW_ST_MODE_TITLE_FLAME_NONE 2
#define SET_WINDOW_ST_MODE_FLAME_NONE		3

#define GAME_TITLEIMAGE "TITLEIMAGE\\Title.png"						//�^�C�g���摜
#define GAME_TITLE_BACKIMAGE "BACKIMAGE\\TITLE_BACK.jpg"			//�^�C�g���w�i�摜

#define GAME_PROLOGUE "BACKIMAGE\\PROLOGUE.jpg"							//�v�����[�O


#define GAME_MAP_1 "GAME_MAP\\A2.png"           //�}�b�v�`�b�v�̉摜
#define GAME_MAP_2 "GAME_MAP\\Cave1-EarthA5.png"
#define GAME_MAP_3 "GAME_MAP\\Cave1-RockA5.png"
#define GAME_MAP_4 "GAME_MAP\\Ruin-F.png"

//�}�b�v��csv
#define GAME_MAP_CSV_1 "GAME_MAP\\F1.csv"				//1�K
#define GAME_MAP_CSV_2 "GAME_MAP\\F2.csv"				//2�K
#define GAME_MAP_CSV_3 "GAME_MAP\\F3.csv"				//3�K
#define GAME_MAP_CSV_4 "GAME_MAP\\F4.csv"				//4�K
#define GAME_MAP_CSV_5 "GAME_MAP\\Boss.csv"				//�{�X
#define GAME_MAP_CSV_6 "GAME_MAP\\map_under.csv"		//map���n
#define GAME_MAP_CSV_7 "GAME_MAP\\Bossmap_under.csv"	//�{�Xmap���n
#define GAME_MAP_CSV_1_K "GAME_MAP\\kaidan.csv"			//1�K�̊K�i
#define GAME_MAP_CSV_2_K "GAME_MAP\\kaidan2.csv"		//2�K�̊K�i
#define GAME_MAP_CSV_3_K "GAME_MAP\\kaidan3.csv"		//3�K�̊K�i
#define GAME_MAP_CSV_4_K "GAME_MAP\\kaidan4.csv"		//4�K�̊K�i

//�}�b�v�̖���
#define GAME_MAP_NAME_SITA		"MAPDATA_SITA"
#define GAME_MAP_F1				"MAPDATA_F1"
#define GAME_MAP_F2				"MAPDATA_F2"
#define GAME_MAP_F3				"MAPDATA_F3"
#define GAME_MAP_F4				"MAPDATA_F4"
#define GAME_MAP_F1_K			"MAPDATA_F1_KAIDAN"
#define GAME_MAP_BOSS_SITA		"MAPDATA_BOSS_UNDER"
#define GAME_MAP_BOSS			"MAPDATA_BOSS"

#define GAME_MAP_BUN_YOKO_CNT_MAX 16		//�e�}�b�v�`�b�v�̉��̍ő啪����
#define GAME_MAP_BUN_TATE_CNT_MAX 16		//�e�}�b�v�`�b�v�̏c�̍ő啪����

#define GAME_MAP_1_YOKO_MAX 16		//GAME_MAP_1�̉��̍ő啪����
#define GAME_MAP_1_TATE_MAX 12		//GAME_MAP_1�̏c�̍ő啪����

#define GAME_MAP_2_YOKO_MAX 8		//GAME_MAP_2�̉��̍ő啪����
#define GAME_MAP_2_TATE_MAX 16	    //GAME_MAP_2�̏c�̍ő啪����

#define GAME_MAP_3_YOKO_MAX 8		//GAME_MAP_3�̉��̍ő啪����
#define GAME_MAP_3_TATE_MAX 16	    //GAME_MAP_3�̏c�̍ő啪����

#define GAME_MAP_4_YOKO_MAX 16		//GAME_MAP_4�̉��̍ő啪����
#define GAME_MAP_4_TATE_MAX 16	    //GAME_MAP_4�̏c�̍ő啪����

#define GAME_MAP_YOKO 50		//�Q�[���}�b�v�̉��T�C�Y
#define GAME_MAP_TATE 38		//�Q�[���}�b�v�̏c�T�C�Y

#define GAME_MAP_YOKO_SIZE 32	//�Q�[���}�b�v��1�}�X�̃T�C�Y
#define GAME_MAP_TATE_SIZE 32

#define GAME_MAP_OK_KIND 100 //�ʍs�ł���}�b�v�̎��
#define GAME_MAP_NG_KIND 100 //�ʍs�ł��Ȃ��}�b�v�̎��

#define GAME_CHARA                "CHARAIMAGE\\char_p04.png"  //�L�����̉摜
#define GAME_CHARA_BUN_YOKO_CNT 12		//�L�����̕�����(��)
#define GAME_CHARA_BUN_TATE_CNT 8       //�L�����̕�����(�c)
#define GAME_CHARA_YOKO_SIZE 24			//�L�����̑傫��(��)
#define GAME_CHARA_TATE_SIZE 32			//�L�����̑傫��(�c)
#define GAME_CHARA_MOTION_NUM 12		//�L�����̉摜��
#define GAME_CHARA_KIND_YOKO 3		//�L�����̉��̎��
#define GAME_CHARA_KIND_TATE 4		//�L�����̏c�̎��

#define GAME_CHARA_START_X 5	    //�L�����̍ŏ��̈ʒu
#define GAME_CHARA_START_Y 1       //�L�����̍ŏ��̈ʒu
#define GAME_CHARA_SPEED 2         //�L�����̃X�s�[�h

//#######�񋓌^#########

enum GAME_SCENE {
	GAME_SCENE_TITLE,	//�^�C�g�����
	GAME_SCENE_PUOLOGUE,	//�v�����[�O���
	GAME_SCENE_PLAY,	//�v���C���
//	GAME_SCENE_GAMEOVER,	//GameOver���
	GAME_SCENE_END		//�G���h���
};

enum CHARA_IMAGE {
	CHARA_KIND_1 = 0,
	CHARA_KIND_2 = 3,
	CHARA_KIND_3 = 6,
	CHARA_KIND_4 = 9,
	CHARA_KIND_5 = 54
}; //�L�����̎�ނ̗񋓌^

struct STRUCT_GAZOU {
	int Handle;			//�摜�̃n���h��
	char FilePath[128];	//�t�@�C���̃p�X
	int X;				//���̈ʒu
	int Y;				//�c�̈ʒu
	int Width;			//���̃T�C�Y
	int Height;			//�c�̃T�C�Y
	int C_Width;		//���̒��S�ʒu
	int C_Height;		//�c�̒��S�ʒu
}; //�摜�\����

struct STRUCT_IMAGE
{
	char FilePath[128];												//�t�@�C���̃p�X
	int Handle[GAME_MAP_BUN_YOKO_CNT_MAX * GAME_MAP_BUN_TATE_CNT_MAX];		//�摜�̃n���h��
	int X[GAME_MAP_BUN_YOKO_CNT_MAX * GAME_MAP_BUN_TATE_CNT_MAX];			//���̈ʒu
	int Y[GAME_MAP_BUN_YOKO_CNT_MAX * GAME_MAP_BUN_TATE_CNT_MAX];			//�c�̈ʒu
	int Width[GAME_MAP_BUN_YOKO_CNT_MAX * GAME_MAP_BUN_TATE_CNT_MAX];		//���̃T�C�Y
	int Height[GAME_MAP_BUN_YOKO_CNT_MAX * GAME_MAP_BUN_TATE_CNT_MAX];		//�c�̃T�C�Y
	int C_Width[GAME_MAP_BUN_YOKO_CNT_MAX * GAME_MAP_BUN_TATE_CNT_MAX];		//���̒��S�ʒu
	int C_Height[GAME_MAP_BUN_YOKO_CNT_MAX * GAME_MAP_BUN_TATE_CNT_MAX];	//�c�̒��S�ʒu

};	//STRUCT_IMAGE�\����

struct STRUCT_MAP
{
	char name[64];	//�}�b�v�̖���
	char FilePath[128];		//�t�@�C���̃p�X
	int data[GAME_MAP_TATE][GAME_MAP_YOKO];	//�}�b�v��CSV�̃f�[�^
	int mapdate_Init[GAME_MAP_TATE][GAME_MAP_YOKO];	//�}�b�v��CSV�f�[�^

	int Handle[GAME_MAP_BUN_YOKO_CNT_MAX*GAME_MAP_BUN_TATE_CNT_MAX];  //�摜�̃n���h��
	int X[GAME_MAP_BUN_YOKO_CNT_MAX*GAME_MAP_BUN_TATE_CNT_MAX];		//���̈ʒu
	int Y[GAME_MAP_BUN_YOKO_CNT_MAX*GAME_MAP_BUN_TATE_CNT_MAX];		//�c�̈ʒu
	int Width[GAME_MAP_BUN_YOKO_CNT_MAX*GAME_MAP_BUN_TATE_CNT_MAX];	//���̃T�C�Y
	int Height[GAME_MAP_BUN_YOKO_CNT_MAX*GAME_MAP_BUN_TATE_CNT_MAX];  //�c�̃T�C�Y
	int C_Width[GAME_MAP_BUN_YOKO_CNT_MAX*GAME_MAP_BUN_TATE_CNT_MAX]; //���̒��S�ʒu
	int C_Height[GAME_MAP_BUN_YOKO_CNT_MAX*GAME_MAP_BUN_TATE_CNT_MAX]; //�c�̒��S�ʒu

	int mapNGKind[GAME_MAP_NG_KIND];					//�}�b�v����̎��(�ʍs�ł��Ȃ�)
	int mapOKKind[GAME_MAP_OK_KIND];					//�}�b�v����̎��(�ʍs�ł���)

	RECT rect_NG[GAME_MAP_TATE][GAME_MAP_YOKO];			//�����蔻��̗̈�(�ʍs�ł��Ȃ�)
	RECT rect_NG_First[GAME_MAP_TATE][GAME_MAP_YOKO];	//�����蔻��̗̈�(�ʍs�ł��Ȃ�)(�ŏ�)

	RECT rect_OK[GAME_MAP_TATE][GAME_MAP_YOKO];			//�����蔻��̗̈�(�ʍs�ł���)
	RECT rect_OK_First[GAME_MAP_TATE][GAME_MAP_YOKO];	//�����蔻��̗̈�(�ʍs�ł���)(�ŏ�)

}; //MAP�\����

struct STRUCT_CHARAIMAGE
{
	char FilePath[128];												//�t�@�C���̃p�X
	int Handle[GAME_CHARA_BUN_YOKO_CNT*GAME_CHARA_BUN_TATE_CNT];	//�摜�̃n���h��
	int X[GAME_CHARA_BUN_YOKO_CNT*GAME_CHARA_BUN_TATE_CNT];			//���̈ʒu
	int Y[GAME_CHARA_BUN_YOKO_CNT*GAME_CHARA_BUN_TATE_CNT];			//�c�̈ʒu
	int Width[GAME_CHARA_BUN_YOKO_CNT*GAME_CHARA_BUN_TATE_CNT];		//�c�̃T�C�Y
	int Height[GAME_CHARA_BUN_YOKO_CNT*GAME_CHARA_BUN_TATE_CNT];	//���̃T�C�Y
	int C_Width[GAME_CHARA_BUN_YOKO_CNT*GAME_CHARA_BUN_TATE_CNT];	//���̒��S�ʒu
	int C_Height[GAME_CHARA_BUN_YOKO_CNT*GAME_CHARA_BUN_TATE_CNT];	//�c�̒��S�ʒu
}; //STRUCT_CHARAIMAGE�\����

struct STRUCT_CHARADATA
{
	STRUCT_CHARAIMAGE charimage;	//�摜
	int Handle[GAME_CHARA_MOTION_NUM];//�摜�̃n���h��
	int X;							//�c�̈ʒu
	int Y;							//���̈ʒu
	int Width;						//���̃T�C�Y
	int Height;						//�c�̃T�C�Y
	int C_Width;					//���̒��S�ʒu
	int C_Height;					//�c�̒��S�ʒu
	int NowHandleNum;				//���݂̉摜�̃n���h��
	int NowHandleCnt;				//���݂̃n���h���J�E���g
	int NowHandleCntMAX;			//���݂̃n���h���J�E���gMAX

	int Speed;						//���x
	int MoveDistX;					//�ړ�����X
	int MoveDistY;					//�ړ�����Y

	BOOL CanMoveUp;					//��ɍs���邩
	BOOL CanMoveDown;				//���̍s���邩
	BOOL CanMoveLeft;				//���̍s���邩
	BOOL CanMoveRight;				//�E�ɍs���邩

	BOOL ScrollOK_X;				//�X�N���[���ł��邩�ǂ���
	BOOL ScrollOK_Y;

	int atariX;			//�����蔻���X�ʒu
	int atariY;			//�����蔻���Y�ʒu
	int atariWidth;		//�����蔻��̕�
	int atariHeight;	//�����蔻��̍���	
	RECT atariRect;		//�����蔻��̋�`�̈�

	char name[255];		//���O


	RECT rect_act;	//�s���̗̈�

	int act_kind;				//�s���̎��
	BOOL IsActKeyDown_left;		//�s�����������Ƃ�(�E)
	BOOL IsActKeyDown_right;	//�s�����������Ƃ�(��)

}; //STRUCT_CHARADATA�\����

//###### ���O�̍Ē�` ########
typedef STRUCT_GAZOU GAZOU;
typedef STRUCT_IMAGE IMAGE;
typedef STRUCT_MAP MAP;
typedef STRUCT_CHARAIMAGE CHARAIMAGE;
typedef STRUCT_CHARADATA CHARADATA;

GAZOU  BackGround;	//�^�C�g���w�i�摜
GAZOU  BackGround_T;  //�^�C�g���摜
GAZOU  BackGround_P;	//�v�����[�O

MAP MapImage;
MAP MapImage_U;  //���n�̃}�b�v�摜
MAP MapImage_W;  //�ǂȂǂ̃}�b�v�摜
MAP MapImage_B;  //�{�X�ʂ̃}�b�v�摜
MAP MapImage_S;  //�K�i�̃}�b�v�摜

//######### �O���[�o���ϐ� #######

//�E�B���h�E�֌W
WNDPROC WndProc;			//�E�B���h�E�v���V�[�W���̃A�h���X
BOOL IsWM_CREATE = FALSE;   //WM_CREATE������ɋN�����������f����

//FPS�֘A
int StartTimeFps;					//����J�n����
int CountFps;						//�J�E���^
float CalcFps;						//�v�Z����
int SampleNumFps = GAME_FPS_SPEED;  //���ς����T���v��

//�L�[�{�[�h�֌W
char AllKeyState[256];	//���ׂẴL�[�̏�Ԃ�����

//�V�[���֌W
int GameSceneNow = (int)GAME_SCENE_TITLE;	//�ŏ��̃Q�[����ʂ��^�C�g����ʂɐݒ�

//�L�����n
CHARAIMAGE CharaImage;		//�L�����̉摜
CHARADATA  Myplayer;		//�L�����̃f�[�^


//�v���C���[�̃C���[�W�摜�̔ԍ���ݒ肷��
int PlayerImageNum[GAME_CHARA_MOTION_NUM];

int ScrollCntYoko = 0;	//�X�N���[���J�E���^(��)
int ScrollDistPlusYoko = 1;  //�X�N���[�����鋗��(��)


int ScrollCntTate = 0;  //�X�N���[���J�E���^(�c)
int ScrollDistPlusTate = 1;  //�X�N���[�����鋗��(�c)

BOOL IsActiveCheck = FALSE;	//��ʂ̃A�N�e�B�u�`�F�b�N�̗L����

int StopActiveStartTime = 0;	//��A�N�e�B�u���̊J�n����
int StopActiveStopTime = 0;		//��A�N�e�B�u���̏I������
int StopActiveTotaTime = 0;		//��A�N�e�B�u���̌o�ߎ���

//####### �v���g�^�C�v�錾 ##########
LRESULT CALLBACK MY_WNDPROC(HWND, UINT, WPARAM, LPARAM); //����E�B���h�E�v���V�[�W��

VOID MY_FPS_UPDATE(VOID);		//FPS�l���v���A�X�V������֐�
VOID MY_FPS_DRAW(VOID);			//FPS�l��`�悷��֐�
VOID MY_FPS_WAIT(VOID);			//FPS�l���v�����A�҂֐�

VOID MY_ALL_KEYDOWN_UPDATE(VOID);	//�L�[���͏�Ԃ��X�V����֐�

VOID MY_GAME_TITLE(VOID);		//�^�C�g�����
VOID MY_GAME_PROLOGUE(VOID);	//�v�����[�O���
VOID MY_GAME_PLAY(VOID);		//�v���C���
VOID MY_GAME_END(VOID);			//�G���h���

VOID MY_PLAY_MAP_DRAW(MAP);			//�}�b�v��\������֐�
VOID MY_PLAY_MAP_DRAW_ATARI(MAP *, MAP *, MAP *);		//�}�b�v�̓����蔻���`�悷��֐�
BOOL MY_GAZOU_LOAD(GAZOU *, int, int, const char *);			//�摜��ǂݍ��ސݒ������֐�

BOOL MY_PLAY_INIT(VOID);	//�������֐�

BOOL MY_MAP_READ_CSV_UE_KIND_SET(MAP *);	//�}�b�v����̎�ނ�ݒ肷��(��)
BOOL MY_MAP_READ_CSV_NAKA_KIND_SET(MAP *);	//�}�b�v����̎�ނ�ݒ肷��(��)
BOOL MY_MAP_READ_CSV_SITA_KIND_SET(MAP *);	//�}�b�v����̎�ނ�ݒ肷��(��)
BOOL MY_MAP_READ_CSV_NUM(MAP * ,const char *, const char *);			//�Q�[���}�b�v��F1CSV��ǂݍ��ފ֐�

BOOL MY_MAP_LOAD_BUNKATSU(MAP *, int, int, int, int, int, const char *);	//MAP�𕪊����ēǂݍ��ސݒ������֐�
BOOL MY_MAP_2_LOAD_BUNKATSU(MAP *, int, int, int, int, int, const char *);	//MAP�𕪊����ēǂݍ��ސݒ������֐�
BOOL MY_MAP_3_LOAD_BUNKATSU(MAP *, int, int, int, int, int, const char *);	//MAP�𕪊����ēǂݍ��ސݒ������֐�
BOOL MY_MAP_4_LOAD_BUNKATSU(MAP *, int, int, int, int, int, const char *);	//MAP�𕪊����ēǂݍ��ސݒ������֐�

BOOL MY_CHARA_LOAD_BUNKATSU(CHARAIMAGE *,int,int,int,int,int, const char *);

BOOL MY_PLAYER_INIT(CHARADATA *, CHARAIMAGE, int *, int, int, int);	//�v���C���[������������֐�
VOID MY_PLAY_PLAYER_DRAW(CHARADATA);	//�v���C���[��\������֐�

VOID MY_PLAY_PLAYER_OPERATION(VOID);						//�v���C���[�𑀍삷��֐�
BOOL MY_PLAY_PLAYER_OPERATION_KEY(int *, int *);			//�v���C���[���L�[���삷��֐�

VOID MY_SET_PLAYER_ATARI(CHARADATA *);			//�v���C���[�̓����蔻��̗̈��ݒ肷��֐�

BOOL MY_CHECK_RECT_ATARI(RECT, RECT);		//�̈�̓����蔻�������֐�
BOOL MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(RECT, RECT map[GAME_MAP_TATE][GAME_MAP_YOKO], int *, int *);

int MapData[GAME_MAP_TATE][GAME_MAP_YOKO];  //�}�b�v�̃f�[�^fp
FILE *fp_map_csv;  //�t�@�C���̊Ǘ��ԍ�(�|�C���^)
int MapData_Init[GAME_MAP_TATE][GAME_MAP_YOKO]; //�}�b�v�̃f�[�^(�������p)

//############ �v���O�����ōŏ��Ɏ��s�����֐� ###########
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	ChangeWindowMode(TRUE);								//�E�B���h�E���[�h�ɐݒ�
	SetGraphMode(GAME_WIDTH, GAME_HEIGHT, GAME_COLOR); //�w��̐��l�ŉ�ʂ�\������

	SetWindowStyleMode(SET_WINDOW_ST_MODE_DEFAULT);		//�^�C�g���o�[����

	SetMainWindowText(TEXT(GAME_WINDOW_NAME));			//�^�C�g������

	if (DxLib_Init() == -1) {			//DX���C�u��������������
		return -1;
	}

	SetDrawScreen(DX_SCREEN_BACK);		//Drow�n�֐��͗���ʂɕ\��

	MY_MAP_READ_CSV_UE_KIND_SET(&MapImage_S);	//�}�b�v�̏�̎�ނ�ݒ�
	MY_MAP_READ_CSV_NAKA_KIND_SET(&MapImage_W);	//�}�b�v�̒��̎�ނ�ݒ�
	MY_MAP_READ_CSV_SITA_KIND_SET(&MapImage_U);	//�}�b�v�̉��̎�ނ�ݒ�

	if (MY_GAZOU_LOAD(&BackGround, 0, 0, GAME_TITLE_BACKIMAGE) == FALSE) {  //�^�C�g���w�i�摜��ǂݍ���
		MessageBox(NULL, GAME_TITLE_BACKIMAGE, "NotFound", MB_OK);
		return -1;
	}


	if (MY_GAZOU_LOAD(&BackGround_T,150,200, GAME_TITLEIMAGE) == FALSE) {  //�^�C�g���摜��ǂݍ���
		MessageBox(NULL, GAME_TITLEIMAGE, "NotFound", MB_OK);
		return -1;
	}

	if (MY_GAZOU_LOAD(&BackGround_P, 0, 0, GAME_PROLOGUE) == FALSE) {  //�v�����[�O�摜��ǂݍ���
		MessageBox(NULL, GAME_PROLOGUE, "NotFound", MB_OK);
		return -1;
	}

	if (MY_MAP_LOAD_BUNKATSU(&MapImage_U, GAME_MAP_1_YOKO_MAX * GAME_MAP_1_TATE_MAX, GAME_MAP_1_YOKO_MAX, GAME_MAP_1_TATE_MAX,  GAME_MAP_YOKO_SIZE, GAME_MAP_TATE_SIZE, GAME_MAP_1) == FALSE) {  //���n�̃}�b�v�`�b�v�摜��ǂݍ���
		MessageBox(NULL, GAME_MAP_1, "NotFound", MB_OK);
		return -1;
	}

	if (MY_MAP_2_LOAD_BUNKATSU(&MapImage_W, GAME_MAP_2_YOKO_MAX * GAME_MAP_2_TATE_MAX, GAME_MAP_2_YOKO_MAX, GAME_MAP_2_TATE_MAX, GAME_MAP_YOKO_SIZE, GAME_MAP_TATE_SIZE, GAME_MAP_2) == FALSE) {  //�ǌn�̃}�b�v�`�b�v�摜��ǂݍ���
		MessageBox(NULL, GAME_MAP_2, "NotFound", MB_OK);
		return -1;
	}

	if (MY_MAP_3_LOAD_BUNKATSU(&MapImage_B, GAME_MAP_3_YOKO_MAX*GAME_MAP_3_TATE_MAX, GAME_MAP_3_YOKO_MAX, GAME_MAP_3_TATE_MAX, GAME_MAP_YOKO_SIZE, GAME_MAP_TATE_SIZE, GAME_MAP_3) == FALSE) {  //�{�X�G���A�̃}�b�v�`�b�v��ǂݍ���
		MessageBox(NULL, GAME_MAP_3, "NotFound", MB_OK);
		return -1;
	}

	if (MY_MAP_4_LOAD_BUNKATSU(&MapImage_S, GAME_MAP_4_YOKO_MAX*GAME_MAP_4_TATE_MAX, GAME_MAP_4_YOKO_MAX, GAME_MAP_4_TATE_MAX, GAME_MAP_YOKO_SIZE, GAME_MAP_TATE_SIZE, GAME_MAP_4) == FALSE) {  //�K�i�̃}�b�v�`�b�v��ǂݍ���
		MessageBox(NULL, GAME_MAP_4, "NotFound", MB_OK);
		return -1;
	}

	if (MY_CHARA_LOAD_BUNKATSU(&CharaImage, GAME_CHARA_BUN_YOKO_CNT*GAME_CHARA_BUN_TATE_CNT, GAME_CHARA_BUN_YOKO_CNT, GAME_CHARA_BUN_TATE_CNT, GAME_CHARA_YOKO_SIZE, GAME_CHARA_TATE_SIZE, GAME_CHARA) == FALSE) {
		MessageBox(NULL, GAME_CHARA, "NotFound", MB_OK);
		return -1;
	}		//GAME_CHARA��ǂݍ���

	MY_MAP_READ_CSV_NUM(&MapImage_W, GAME_MAP_CSV_1, GAME_MAP_F1);		    //�}�b�v�P�̏��ǂݍ��݁A�����蔻��̗̈������
	MY_MAP_READ_CSV_NUM(&MapImage_S, GAME_MAP_CSV_1_K, GAME_MAP_F1_K);		//�}�b�v�P�̊K�i��ǂݍ��݁A�����蔻��̗̈������
	MY_MAP_READ_CSV_NUM(&MapImage_U, GAME_MAP_CSV_6, GAME_MAP_NAME_SITA);	//�}�b�v�P�̉���ǂݍ��݁A�����蔻��̗̈������

	IsActiveCheck = TRUE;

	while (TRUE)		//�������[�v
	{
		if (ProcessMessage() != 0)	//���b�Z�[�W�����̌��ʂ��G���[�̂Ƃ��A�����I��
		{
			break;
		}

		if (ClearDrawScreen() != 0) {	//��ʂ������ł��Ȃ��������A�����I��
			break;
		}

        MY_ALL_KEYDOWN_UPDATE();		//�L�[�̏�Ԃ��擾

		switch (GameSceneNow)	//�V�[���I��
		{
		case(int)GAME_SCENE_TITLE:	//�^�C�g����ʂ̏�����������

			MY_GAME_TITLE();	//�^�C�g����ʂ̏���

			break;	//�^�C�g����ʂ̏��������܂�
		

		case(int)GAME_SCENE_PUOLOGUE:	//�v�����[�O��ʂ̏�����������

			MY_GAME_PROLOGUE();	//�v�����[�O��ʂ̏���

			break;	//�v�����[�O��ʂ̏��������܂�

		case (int)GAME_SCENE_PLAY:	//�v���C��ʂ̏�����������

			MY_GAME_PLAY();	//�v���C��ʂ̏���

			break;	//�v���C��ʂ̏��������܂�

		case (int)GAME_SCENE_END:	//�G���h��ʂ̏�����������

			MY_GAME_END();	//�G���h��ʂ̏���

			break;	//�G���h��ʂ̏��������܂�

		default:

			break;
		}
		MY_FPS_UPDATE();		//FPS�̏���(�X�V)
		
		MY_FPS_DRAW();			//FPS�̏���(�`��)

		ScreenFlip();			//���j�^�̃��t���b�V�����[�g�̑����ŗ���ʂ��ĕ`��

		MY_FPS_WAIT();			//FPS�̏���(�҂�)

	}

	DeleteGraph(BackGround.Handle);	//�w�i�̃n���h�����폜

	DeleteGraph(BackGround_T.Handle);	//�^�C�g���摜�̃n���h�����폜

	DeleteGraph(BackGround_P.Handle);	//�v�����[�O�摜�̃n���h�����폜

	for (int mapCnt = 0; mapCnt < GAME_MAP_1_YOKO_MAX * GAME_MAP_1_TATE_MAX; mapCnt++)
	{
		DeleteGraph(MapImage_U.Handle[mapCnt]);	//�}�b�v1�̃n���h�����폜
	}

	for (int mapCnt = 0; mapCnt < GAME_MAP_2_YOKO_MAX * GAME_MAP_2_TATE_MAX; mapCnt++)
	{
		DeleteGraph(MapImage_W.Handle[mapCnt]);	//�}�b�v2�̃n���h�����폜
	}

	for (int mapCnt = 0; mapCnt < GAME_MAP_3_YOKO_MAX * GAME_MAP_3_TATE_MAX; mapCnt++)
	{
		DeleteGraph(MapImage_B.Handle[mapCnt]);	//�}�b�v3�̃n���h�����폜
	}

	for (int mapCnt = 0; mapCnt < GAME_MAP_4_YOKO_MAX * GAME_MAP_4_TATE_MAX; mapCnt++)
	{
		DeleteGraph(MapImage_S.Handle[mapCnt]);	//�}�b�v4�̃n���h�����폜
	}

	DxLib_End();	//DX���C�u�����g�p�̏I������

	return 0;
}


//###### FPS�l���v���A�X�V����֐� #######
VOID MY_FPS_UPDATE(VOID)
{
	if (CountFps == 0)	 //1�t���[���ڂȂ玞�����L��
	{
		StartTimeFps = GetNowCount();
	}

	if (CountFps == SampleNumFps)	//60�t���[���ڂȂ畽�ς��v�Z
	{
		int now = GetNowCount();
		CalcFps = 1000.f / ((now - StartTimeFps) / (float)SampleNumFps);
		CountFps = 0;
		StartTimeFps = now;
	}
	CountFps++;
	return;
}

//########## FPS�l��`�悷��֐� #########
VOID MY_FPS_DRAW(VOID)
{
	//�������`��
	DrawFormatString(0, GAME_HEIGHT - 20, GetColor(0, 0, 0), "FPS:%.1f", CalcFps);
	return;
}

//####### FPS�l���v�����A�҂֐� #########
VOID MY_FPS_WAIT(VOID)
{
	int resultTime = GetNowCount() - StartTimeFps;	//������������
	int waitTime = CountFps * 1000 / GAME_FPS_SPEED - resultTime;	//�҂ׂ�����

	if (waitTime > 0)	//�w���FPS�l���������ꍇ
	{
		Sleep(waitTime);	//�҂�
	}
	return;

}

//####### �L�[���͏�Ԃ��X�V����֐� ######
VOID MY_ALL_KEYDOWN_UPDATE(VOID)
{
	char TempKey[256];	//�ꎞ�I�ɁA���݂̃L�[�̓��͏�Ԃ��i�[����

	GetHitKeyStateAll(TempKey);	//���ׂẴL�[�̓��͏�Ԃ𓾂�

	for (int i = 0; i < 256; i++)
	{
		if (TempKey[i] != 0)	//������Ă���L�[�̃L�[�R�[�h�������Ă���Ƃ�
		{
			AllKeyState[i]++;	//������Ă���
		}
		else
		{
			AllKeyState[i] = 0;	//������Ă��Ȃ�
		}
	}
	return;
}

//######## �^�C�g����ʂ̊֐� #############
VOID MY_GAME_TITLE(VOID)
{
	if (AllKeyState[KEY_INPUT_RETURN] != 0)
	{
		if (MY_PLAY_INIT() == TRUE)
		{
			GameSceneNow = (int)GAME_SCENE_PUOLOGUE;	//�v�����[�O��ʂɑJ��
		}
	}


	DrawGraph( BackGround.X, BackGround.Y, BackGround.Handle, TRUE);		//�^�C�g���w�i�摜�`��

	DrawGraph(BackGround_T.X, BackGround_T.Y, BackGround_T.Handle, TRUE);		//�^�C�g���摜�`��

	DrawString(0, 0, "�^�C�g�����(�G���^�[�L�[�������Ă�������)", GetColor(0, 0, 0));
	return;
}


//####### �v�����[�O��ʂ̊֐� ############# 
VOID MY_GAME_PROLOGUE(VOID)
{
	if (AllKeyState[KEY_INPUT_SPACE] != 0)
	{
		GameSceneNow = (int)GAME_SCENE_PLAY;	//�v���C��ʂɑJ��
	}

	DrawGraph(BackGround_P.X, BackGround_P.Y, BackGround_P.Handle, TRUE);	//�v�����[�O�摜�`��

	DrawString(0, 550, "SPACE�ŃX�L�b�v", GetColor(0, 0, 0));

	return;
}

//########### �v���C��ʂ̊֐� ############
VOID MY_GAME_PLAY(VOID)
{
	MY_PLAY_PLAYER_OPERATION();

	MY_PLAY_MAP_DRAW(MapImage_U);	//�}�b�v��`��

	MY_PLAY_MAP_DRAW(MapImage_S);	//�}�b�v��`��

	MY_PLAY_MAP_DRAW(MapImage_W);	//�}�b�v��`��

	MY_PLAY_PLAYER_DRAW(Myplayer);

	//MY_PLAY_MAP_DRAW_ATARI(&MapImage_W, &MapImage_W, &MapImage_U);

	DrawString(0, 0,"�v���C���(A�L�[�������Ă�������)", GetColor(255, 255, 255));

	if (AllKeyState[KEY_INPUT_A] != 0)
	{
		GameSceneNow = (int)GAME_SCENE_END;
	}
}

VOID MY_GAME_END(VOID)
{
	if (AllKeyState[KEY_INPUT_BACK] != 0)
	{
		GameSceneNow = (int)GAME_SCENE_TITLE;
	}

	DrawString(0, 0, "�G���h���(�o�b�N�X�y�[�X�L�[�������Ă�������)", GetColor(255, 255, 255));

	return;
}

//########## �������֐� ##########
BOOL MY_PLAY_INIT(VOID)
{
	ScrollCntYoko = 0;	//�X�N���[���ʂ�������
	ScrollCntTate = 0;

	//�v���C���[�̉摜�̔ԍ���ݒ�
	int StartNum = (int)CHARA_KIND_5;
	int soeji = 0;
	PlayerImageNum[soeji++] = StartNum + 0;
	PlayerImageNum[soeji++] = StartNum + 1;
	PlayerImageNum[soeji++] = StartNum + 2;
	PlayerImageNum[soeji++] = StartNum + 12;
	PlayerImageNum[soeji++] = StartNum + 13;
	PlayerImageNum[soeji++] = StartNum + 14;
	PlayerImageNum[soeji++] = StartNum + 24;
	PlayerImageNum[soeji++] = StartNum + 25;
	PlayerImageNum[soeji++] = StartNum + 26;
	PlayerImageNum[soeji++] = StartNum + 36;
	PlayerImageNum[soeji++] = StartNum + 37;
	PlayerImageNum[soeji++] = StartNum + 38;

	//�v���C���[��������
	if (MY_PLAYER_INIT(&Myplayer, CharaImage, &PlayerImageNum[0], GAME_MAP_YOKO_SIZE*GAME_CHARA_START_X, GAME_MAP_TATE_SIZE*GAME_CHARA_START_Y, GAME_CHARA_SPEED) == FALSE) {
		MessageBox(NULL, "CHARA_INIT", "NotFound", MB_OK);
		return FALSE;
	}


	return TRUE;
}

//########## �v���C���[������������֐� ##########
//���@���FCHARADATA �\���́F�ݒ肷��CHARADATA�\����
//���@���FCHARAIMAGE�\���́F�ݒ肷��CHARAIMAGE�\����
//���@���Fint* �@�@ �@�@�@�F�g�p����摜�̔ԍ��i�z��̐擪�A�h���X�������Ƃ���j
//���@���Fint�@	�@�@�@�@�@�F�摜�̏����ʒuX
//���@���Fint�@	�@�@�@�@�@�F�摜�̏����ʒuY
//���@���Fint�@	�@�@�@�@�@�F�ړ��X�s�[�h
//�߂�l�FBOOL�F�G���[���FFALSE
BOOL MY_PLAYER_INIT(CHARADATA *charadata, CHARAIMAGE charaimage, int *num, int x, int y, int speed)
{
	//*(num+0)�Δz��̐擪�A�h���X
	for (int mot = 0; mot < GAME_CHARA_MOTION_NUM; mot++)
	{
		charadata->Handle[mot] = charaimage.Handle[*(num + mot)];	//�摜�̃n���h��������
	}

	charadata->X = x;
	charadata->Y = y;
	charadata->Width = charaimage.Width[*(num + 0)];      //�ŏ��̉摜�̉�����ݒ肷��
	charadata->Height = charaimage.Height[*(num + 0)];	  //�ŏ��̉摜�̍�����ݒ肷��
	charadata->C_Width = charaimage.C_Width[*(num + 0)];  //�ŏ��̉摜�̉����̒��S��ݒ肷��
	charadata->C_Height = charaimage.C_Height[*(num + 0)]; //�ŏ��̉摜�̍�����ݒ肷��

	//�}�b�v�������Ɠ����傫���ɂ���
	charadata->Width = GAME_MAP_YOKO_SIZE;
	charadata->Height = GAME_MAP_TATE_SIZE;
	charadata->C_Width = GAME_MAP_YOKO_SIZE / 2;
	charadata->C_Height = GAME_MAP_TATE_SIZE / 2;

	charadata->NowHandleNum = 6;	//�O�����̍ŏ��̉摜
	charadata->NowHandleCnt = 0;	//�摜�J�E���^��������

	charadata->NowHandleCntMAX = 6; //�摜�J�E���^MAX��������

	//*************  �p�����[�^�ݒ�  ********************************
	charadata->Speed = speed;

	charadata->MoveDistX = x;		//���̋������}�b�v�̍ŏ����瓮���������Ƃ��Đݒ肷��
	charadata->MoveDistY = y;		

	charadata->CanMoveUp = TRUE;		//��Ɉړ��ł���
	charadata->CanMoveDown = TRUE;		//���Ɉړ��ł���
	charadata->CanMoveLeft = TRUE;		//���Ɉړ��ł���
	charadata->CanMoveRight = TRUE;		//�E�Ɉړ��ł���

	charadata->ScrollOK_X = FALSE;	//�ړ��ł��Ȃ�
	charadata->ScrollOK_Y = FALSE;

	charadata->atariX = 4;				//�����蔻���X�ʒu�𒚓x�ǂ��ݒ�
	charadata->atariY = 10;				//�����蔻���Y�ʒu�𒚓x�ǂ��ݒ�
	charadata->atariWidth = 18;			//�����蔻��̕��𒚓x�ǂ��ݒ�
	charadata->atariHeight = 24;		//�����蔻��̍����𒚓x�ǂ��ݒ�

	//wsprintf(charadata->name, GAME_PLAYER_NAME);

	MY_SET_PLAYER_ATARI(charadata);	//�v���C���[�̓����蔻��̗̈��ݒ�

	return TRUE;
}

//########## �L�����N�^�[�ƃ}�b�v�̓����蔻�������֐�(���������ꏊ��m��) ##########
//���@���@�FRECT	�F�����蔻�������̈�(�L�����N�^�[)
//���@���@�FRECT	�F�����蔻�������̈�(�}�b�v)
//���@���@�Fint 	�F���������ꏊ(X�ʒu)
//���@���@�Fint 	�F���������ꏊ(Y�ʒu)
//�߂�l�@�F�������Ă���FTRUE / �������Ă��Ȃ� / FALSE
BOOL MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(RECT chara, RECT map[GAME_MAP_TATE][GAME_MAP_YOKO], int *atariX, int *atariY)
{
	for (int tate = 0; tate < GAME_MAP_TATE; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO; yoko++)
		{
			//�L�����̓������Ă���ꏊ���擾
			if (MY_CHECK_RECT_ATARI(chara, map[tate][yoko]) == TRUE)
			{
				*atariY = tate;	//atariY�̃A�h���X���w����̏ꏊ�ɁA�����������m�̏c�̈ʒu������
				*atariX = yoko;	//atariX�̃A�h���X���w����̏ꏊ�ɁA�����������m�̏c�̈ʒu������

				return TRUE;
			}
		}
	}
	return FALSE;	//�������ĂȂ�
}

//######### �̈�̓����蔻�������֐� #########
BOOL MY_CHECK_RECT_ATARI(RECT a, RECT b)
{
	if (a.left<b.right&&
		a.top<b.bottom&&
		a.right>b.left&&
		a.bottom>b.top
		)
	{
		return TRUE;	//�������Ă���
	}

	return FALSE;	//�������Ă��Ȃ�
}

//########## �v���C���[�̓����蔻��̗̈��ݒ肷��֐� ###########
VOID MY_SET_PLAYER_ATARI(CHARADATA *charadata)
{
	//�����蔻��̗̈��ݒ�
	charadata->atariRect.left = charadata->X + charadata->atariX + 2;								//���݂�X�ʒu�{�����蔻���X�̈ʒu
	charadata->atariRect.top = charadata->Y + charadata->atariY + 2;								//���݂�Y�ʒu�{�����蔻���Y�̈ʒu
	charadata->atariRect.right = charadata->X + charadata->atariX + charadata->atariWidth - 2;		//���݂�X�ʒu�{�����蔻���X�̈ʒu�{�����蔻��̕�
	charadata->atariRect.bottom = charadata->Y + charadata->atariY + charadata->atariHeight - 2;	//���݂�Y�ʒu�{�����蔻���Y�̈ʒu�{�����蔻��̍���

	return;
}

//########## �v���C���[�𑀍삷��֐� ###########
VOID MY_PLAY_PLAYER_OPERATION(VOID)
{
	int retAtariX = 0;  //�������Ă���}�b�v�̏ꏊ
	int retAtariY = 0;

	BOOL IsKeyDown = MY_PLAY_PLAYER_OPERATION_KEY(&retAtariX, &retAtariY);	//�L�[�������Ă��邩���f

	return;
}

//########### �v���C���[���L�[���삷��֐� #########

BOOL MY_PLAY_PLAYER_OPERATION_KEY(int *x, int *y)
{
	BOOL IsKeyDown = FALSE;	//�L�[�������ꂽ��

	if (AllKeyState[KEY_INPUT_LEFT] != 0)	//�����L�[��������Ă����Ƃ�
	{
		IsKeyDown = TRUE;	//�L�[�������ꂽ

		Myplayer.CanMoveLeft = TRUE;	//�������ɁA�܂�������

		MY_SET_PLAYER_ATARI(&Myplayer);	//�v���C���[�̓����蔻��̈��ݒ�
		Myplayer.atariRect.left -= 4;	//���������蔻��̗̈�����ɂ��炷
		Myplayer.atariRect.right -= 4;	//���������蔻��̗̈�����ɂ��炷

		if (MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(Myplayer.atariRect,MapImage_W.rect_NG, x, y) == TRUE)
		{
			Myplayer.CanMoveLeft = FALSE;	//	���ɍs���Ȃ�
		}

		if (Myplayer.CanMoveLeft == TRUE)	//���Ɉړ��ł���Ƃ�
		{
			if (Myplayer.ScrollOK_X == FALSE)	//�X�N���[���ł��Ȃ��Ƃ�
			{
				if (Myplayer.X > 0)
				{
					Myplayer.X -= Myplayer.Speed;	//�v���C���[�����Ɉړ�
				}
			}
			else   //�X�N���[���ł���Ƃ�
			{
				if (ScrollCntYoko > 0)  //�}�b�v�O�փX�N���[�����Ȃ�
				{
					ScrollCntYoko -= Myplayer.Speed;	//��ʂ����ɃX�N���[��	
				}
			}

			if (Myplayer.MoveDistX > 0)
			{
				Myplayer.MoveDistX -= Myplayer.Speed;
			}

		}
	}
	if (AllKeyState[KEY_INPUT_RIGHT] != 0)	//�E���L�[��������Ă�����
	{
		IsKeyDown = TRUE;

		Myplayer.CanMoveRight = TRUE;

		MY_SET_PLAYER_ATARI(&Myplayer);	//�v���C���[�̓����蔻��̗̈��ݒ�
		Myplayer.atariRect.left += 4;	//�����A�v���C���[�̓����蔻��̗̈���E�ɂ��炷
		Myplayer.atariRect.right += 4;	//�����A�v���C���[�̓����蔻��̗̈���E�ɂ��炷

		if (MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(Myplayer.atariRect, MapImage_W.rect_NG, x, y) == TRUE)	//�E�ɍs���Ȃ����̂Ɠ��������Ƃ�
		{
			Myplayer.CanMoveRight = FALSE;	//�E�ɍs���Ȃ�
		}

		if (Myplayer.CanMoveRight == TRUE)
		{
			if (Myplayer.ScrollOK_X == FALSE)
			{
				if (Myplayer.X + Myplayer.Width < GAME_WIDTH)
				{
					Myplayer.X += Myplayer.Speed;
				}
			}
			else
			{
				if (ScrollCntYoko < GAME_MAP_YOKO_SIZE*GAME_MAP_YOKO)
				{
					ScrollCntYoko += Myplayer.Speed;
				}
			}

			if (Myplayer.MoveDistX < GAME_MAP_YOKO_SIZE*GAME_MAP_YOKO)
			{
				Myplayer.MoveDistX += Myplayer.Speed;
			}
		}
	}

			if (AllKeyState[KEY_INPUT_UP] != 0)		//����L�[��������Ă���Ƃ�
			{
				IsKeyDown = TRUE;

				Myplayer.CanMoveUp = TRUE;	//������ɂ܂�������

				MY_SET_PLAYER_ATARI(&Myplayer);
				Myplayer.atariRect.top -= 4;
				Myplayer.atariRect.bottom -= 4;

				if (MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(Myplayer.atariRect, MapImage_W.rect_NG, x, y) == TRUE)
				{
					Myplayer.CanMoveUp = FALSE;	//��ɍs���Ȃ�
				}

				if (Myplayer.CanMoveUp == TRUE)		//��Ɉړ��ł���Ƃ�
				{
					if (Myplayer.ScrollOK_Y == FALSE)
					{
						if (Myplayer.Y > 0)
						{
							Myplayer.Y -= Myplayer.Speed;
						}
					}
					else
					{
						if (ScrollCntTate > 0)
						{
							ScrollCntTate -= Myplayer.Speed;
						}
					}

					if (Myplayer.MoveDistY > 0)
					{
						Myplayer.MoveDistY -= Myplayer.Speed;
					}
				}
			}
			

			if (AllKeyState[KEY_INPUT_DOWN] != 0)	//�����L�[��������Ă�����
			{
				IsKeyDown = TRUE;

				Myplayer.CanMoveDown = TRUE;

				Myplayer.CanMoveDown = TRUE;	//������ɂ܂�������

				MY_SET_PLAYER_ATARI(&Myplayer);
				Myplayer.atariRect.top += 4;
				Myplayer.atariRect.bottom += 4;

				if (MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(Myplayer.atariRect, MapImage_W.rect_NG, x, y) == TRUE)
				{
					Myplayer.CanMoveDown = FALSE;	//��ɍs���Ȃ�
				}

				if (Myplayer.CanMoveDown == TRUE)	//���Ɉړ��ł���Ƃ�
				{
					if (Myplayer.ScrollOK_Y == FALSE)
					{
						if (Myplayer.Y + Myplayer.Width < GAME_HEIGHT)
						{
							Myplayer.Y += Myplayer.Speed;
						}
					}
					else
					{
						if (ScrollCntTate < GAME_MAP_TATE_SIZE*GAME_MAP_TATE)
						{
							ScrollCntTate += Myplayer.Speed;
						}
					}

					if (Myplayer.MoveDistY < GAME_MAP_TATE_SIZE*(GAME_MAP_TATE - 1))
					{
						Myplayer.MoveDistY += Myplayer.Speed;
					}
				}
			}

			//�}�b�v�̍����ɂ���Ƃ��́A�v���C���[�𓮂���
			if (Myplayer.MoveDistX > 0 &&
				Myplayer.MoveDistX <= GAME_MAP_YOKO_SIZE * 10)	//�v���C���[�̓��������������ȏ�ł����
			{
				Myplayer.ScrollOK_X = FALSE;					//�}�b�v���~�߂āA�v���C���[�𓮂���
			}

			//�}�b�v�̐^�񒆂�����ɂ���Ƃ��́A�}�b�v�𓮂���
			if (Myplayer.MoveDistX > GAME_MAP_YOKO_SIZE * 10 &&
				Myplayer.MoveDistX <= GAME_MAP_YOKO_SIZE * (GAME_MAP_YOKO - 15))
			{
				Myplayer.ScrollOK_X = TRUE;					//�}�b�v�𓮂���
			}

			//�}�b�v�̉E���ɂ���Ƃ��́A�v���C���[�𓮂���
			if (Myplayer.MoveDistX > GAME_MAP_YOKO_SIZE*(GAME_MAP_YOKO - 15) &&
				Myplayer.MoveDistX <= GAME_MAP_YOKO_SIZE * GAME_MAP_YOKO)
			{
				Myplayer.ScrollOK_X = FALSE;				//�}�b�v���~�߂āA�v���C���[�𓮂���
			}

			//�}�b�v�̏㑤�ɂ���Ƃ��́A�v���C���[�𓮂���
			if (Myplayer.MoveDistY > 0 &&
				Myplayer.MoveDistY <= GAME_MAP_TATE_SIZE * 10)
			{
				Myplayer.ScrollOK_Y = FALSE;				//�}�b�v���~�߂āA�v���C���[�𓮂���
			}

			//�}�b�v�̐^�񒆂�����ɂ���Ƃ��́A�}�b�v�𓮂���
			if (Myplayer.MoveDistY > GAME_MAP_TATE_SIZE * 10 &&
				Myplayer.MoveDistY <= GAME_MAP_TATE_SIZE * (GAME_MAP_TATE - 9))	//�v���C���[�̓��������������ȏ�ł����(�J�n�n�_)
			{
				Myplayer.ScrollOK_Y = TRUE;				//�}�b�v�𓮂���
			}

			//�}�b�v�̉����ɂ���Ƃ��́A�v���C���[�𓮂���
			if (Myplayer.MoveDistY > GAME_MAP_TATE_SIZE*(GAME_MAP_TATE - 9) &&	//�v���C���[�̓��������������ȏ�ł����(�I���n�_)
				Myplayer.MoveDistY <= GAME_MAP_TATE_SIZE * GAME_MAP_TATE)
			{
				Myplayer.ScrollOK_Y = FALSE;	//�}�b�v���~�߂āA�v���C���[�𓮂���
			}

	return IsKeyDown;
}

//########## �摜��ǂݍ��ސݒ������֐� ##########
//���@���F�摜�\���́@�F�ݒ肷��摜�\���̂̕ϐ�
//���@���Fint�@�F�摜�̉��̈ʒu
//���@���Fint�@�F�摜�̏c�̈ʒu
//���@���Fconst char *�F�ǂݍ��މ摜�̃t�@�C���p�X
//�߂�l�FBOOL�F�G���[���FFALSE
BOOL MY_GAZOU_LOAD(GAZOU *g, int x, int y, const char *path)
{
	wsprintf(g->FilePath, path);						//�t�@�C���p�X���R�s�[
	g->Handle = LoadGraph(g->FilePath);					//�摜���������ɓǂݍ��݁A�n���h�����擾

	if (g->Handle == -1) { return FALSE; }				//�摜�ǂݍ��݃G���[

	GetGraphSize(g->Handle, &g->Width, &g->Height);		//�摜�T�C�Y���擾
	g->X = x;
	g->Y = y;
	g->C_Width = g->Width / 2;							//�摜�̉��T�C�Y�̒��S���擾
	g->C_Height = g->Height / 2;						//�摜�̏c�T�C�Y�̒��S���擾

	return TRUE;
}

//########## MAP�𕪊����ēǂݍ��ސݒ������֐� ##########
//���@���FMAP�\���́@�F�ݒ肷��摜�\����(����)�̕ϐ�
//���@���Fint�@�F�摜�̕�����
//���@���Fint�@�F�摜�̉��̕�����
//���@���Fint�@�F�摜�̏c�̕�����
//���@���Fint�@�F�摜�̉��̕����T�C�Y
//���@���Fint�@�F�摜�̏c�̕����T�C�Y
//���@���Fconst char *�F�ǂݍ��މ摜�̃t�@�C���p�X
//�߂�l�FBOOL�F�G���[���FFALSE
BOOL MY_MAP_LOAD_BUNKATSU(MAP *m, int bun_num, int bun_x_num, int bun_y_num, int bun_width, int bun_height, const char *path)
{
	int ret = 0;
														//�摜���������ɕ������ēǂݍ��݁A�n���h�����擾
	ret = LoadDivGraph(path, bun_num, bun_x_num, bun_y_num, bun_width, bun_height, m->Handle);

	if (ret == -1) { return FALSE; }	//�摜�ǂݍ��݃G���[

	for (int cnt = 0; cnt < GAME_MAP_1_YOKO_MAX * GAME_MAP_1_TATE_MAX; cnt++)
	{
		//�摜�T�C�Y���擾
		GetGraphSize(
			m->Handle[cnt],		//�n���h������A�摜�̕��ƍ������擾
			&m->Width[cnt],		//MAP�\���̂̕��@�ɁA�摜�̕��@��ݒ肷��
			&m->Height[cnt]);	//MAP�\���̂̋t���ɁA�摜�̍�����ݒ肷��			

		m->C_Width[cnt] = m->Width[cnt] / 2;			//�摜�̉��T�C�Y�̒��S���擾
		m->C_Height[cnt] = m->Height[cnt] / 2;			//�摜�̏c�T�C�Y�̒��S���擾
	}

	return TRUE;
}


//########## MAP�𕪊����ēǂݍ��ސݒ������֐� ##########
//���@���FMAP�\���́@�F�ݒ肷��摜�\����(����)�̕ϐ�
//���@���Fint�@�F�摜�̕�����
//���@���Fint�@�F�摜�̉��̕�����
//���@���Fint�@�F�摜�̏c�̕�����
//���@���Fint�@�F�摜�̉��̕����T�C�Y
//���@���Fint�@�F�摜�̏c�̕����T�C�Y
//���@���Fconst char *�F�ǂݍ��މ摜�̃t�@�C���p�X
//�߂�l�FBOOL�F�G���[���FFALSE
BOOL MY_MAP_2_LOAD_BUNKATSU(MAP *m, int bun_num, int bun_x_num, int bun_y_num, int bun_width, int bun_height, const char *path)
{
	int ret = 0;
	wsprintf(m->FilePath, path);						//�t�@�C���p�X���R�s�[

														//�摜���������ɕ������ēǂݍ��݁A�n���h�����擾
	ret = LoadDivGraph(m->FilePath, bun_num, bun_x_num, bun_y_num, bun_width, bun_height, m->Handle);

	if (ret == -1) { return FALSE; }	//�摜�ǂݍ��݃G���[

	for (int cnt = 0; cnt < GAME_MAP_2_YOKO_MAX * GAME_MAP_2_TATE_MAX; cnt++)
	{
		//�摜�T�C�Y���擾
		GetGraphSize(
			m->Handle[cnt],		//�n���h������A�摜�̕��ƍ������擾
			&m->Width[cnt],		//MAP�\���̂̕��@�ɁA�摜�̕��@��ݒ肷��
			&m->Height[cnt]);	//MAP�\���̂̋t���ɁA�摜�̍�����ݒ肷��			

		m->C_Width[cnt] = m->Width[cnt] / 2;			//�摜�̉��T�C�Y�̒��S���擾
		m->C_Height[cnt] = m->Height[cnt] / 2;			//�摜�̏c�T�C�Y�̒��S���擾
	}

	return TRUE;
}

//########## MAP�𕪊����ēǂݍ��ސݒ������֐� ##########
//���@���FMAP�\���́@�F�ݒ肷��摜�\����(����)�̕ϐ�
//���@���Fint�@�F�摜�̕�����
//���@���Fint�@�F�摜�̉��̕�����
//���@���Fint�@�F�摜�̏c�̕�����
//���@���Fint�@�F�摜�̉��̕����T�C�Y
//���@���Fint�@�F�摜�̏c�̕����T�C�Y
//���@���Fconst char *�F�ǂݍ��މ摜�̃t�@�C���p�X
//�߂�l�FBOOL�F�G���[���FFALSE
BOOL MY_MAP_3_LOAD_BUNKATSU(MAP *m, int bun_num, int bun_x_num, int bun_y_num, int bun_width, int bun_height, const char *path)
{
	int ret = 0;
	wsprintf(m->FilePath, path);						//�t�@�C���p�X���R�s�[

														//�摜���������ɕ������ēǂݍ��݁A�n���h�����擾
	ret = LoadDivGraph(m->FilePath, bun_num, bun_x_num, bun_y_num, bun_width, bun_height, m->Handle);

	if (ret == -1) { return FALSE; }	//�摜�ǂݍ��݃G���[

	for (int cnt = 0; cnt < GAME_MAP_3_YOKO_MAX * GAME_MAP_3_TATE_MAX; cnt++)
	{
		//�摜�T�C�Y���擾
		GetGraphSize(
			m->Handle[cnt],		//�n���h������A�摜�̕��ƍ������擾
			&m->Width[cnt],		//MAP�\���̂̕��@�ɁA�摜�̕��@��ݒ肷��
			&m->Height[cnt]);	//MAP�\���̂̋t���ɁA�摜�̍�����ݒ肷��			

		m->C_Width[cnt] = m->Width[cnt] / 2;			//�摜�̉��T�C�Y�̒��S���擾
		m->C_Height[cnt] = m->Height[cnt] / 2;			//�摜�̏c�T�C�Y�̒��S���擾
	}

	return TRUE;
}

//########## MAP�𕪊����ēǂݍ��ސݒ������֐� ##########
//���@���FMAP�\���́@�F�ݒ肷��摜�\����(����)�̕ϐ�
//���@���Fint�@�F�摜�̕�����
//���@���Fint�@�F�摜�̉��̕�����
//���@���Fint�@�F�摜�̏c�̕�����
//���@���Fint�@�F�摜�̉��̕����T�C�Y
//���@���Fint�@�F�摜�̏c�̕����T�C�Y
//���@���Fconst char *�F�ǂݍ��މ摜�̃t�@�C���p�X
//�߂�l�FBOOL�F�G���[���FFALSE
BOOL MY_MAP_4_LOAD_BUNKATSU(MAP *m, int bun_num, int bun_x_num, int bun_y_num, int bun_width, int bun_height, const char *path)
{
	int ret = 0;
	wsprintf(m->FilePath, path);						//�t�@�C���p�X���R�s�[

														//�摜���������ɕ������ēǂݍ��݁A�n���h�����擾
	ret = LoadDivGraph(m->FilePath, bun_num, bun_x_num, bun_y_num, bun_width, bun_height, m->Handle);

	if (ret == -1) { return FALSE; }	//�摜�ǂݍ��݃G���[

	for (int cnt = 0; cnt < GAME_MAP_4_YOKO_MAX * GAME_MAP_4_TATE_MAX; cnt++)
	{
		//�摜�T�C�Y���擾
		GetGraphSize(
			m->Handle[cnt],		//�n���h������A�摜�̕��ƍ������擾
			&m->Width[cnt],		//MAP�\���̂̕��@�ɁA�摜�̕��@��ݒ肷��
			&m->Height[cnt]);	//MAP�\���̂̋t���ɁA�摜�̍�����ݒ肷��			

		m->C_Width[cnt] = m->Width[cnt] / 2;			//�摜�̉��T�C�Y�̒��S���擾
		m->C_Height[cnt] = m->Height[cnt] / 2;			//�摜�̏c�T�C�Y�̒��S���擾
	}

	return TRUE;
}

//########## CHARA�𕪊����ēǂݍ��ސݒ������֐� ##########
//���@���FCHARAIMAGE�\���́@�F�ݒ肷��CHARAIMAGE�\����(����)�̕ϐ�
//���@���Fint�@�F�摜�̕�����
//���@���Fint�@�F�摜�̉��̕�����
//���@���Fint�@�F�摜�̏c�̕�����
//���@���Fint�@�F�摜�̉��̕����T�C�Y
//���@���Fint�@�F�摜�̏c�̕����T�C�Y
//���@���Fconst char *�F�ǂݍ��މ摜�̃t�@�C���p�X
//�߂�l�FBOOL�F�G���[���FFALSE
BOOL MY_CHARA_LOAD_BUNKATSU(CHARAIMAGE *c, int bun_num, int bun_x_num, int bun_y_num, int bun_width, int bun_height, const char *path)
{
	int retLoad;

	wsprintf(c->FilePath, path);  //�t�@�C���̃p�X���R�s�[

	
	retLoad = LoadDivGraph(c->FilePath, bun_num, bun_x_num, bun_y_num, bun_width, bun_height, c->Handle);	//�摜���������ɕ������ēǂݍ��݁A�n���h�����擾

	if (retLoad == -1) { return FALSE; }	//�摜�ǂݍ��݃G���[

	for (int cnt = 0; cnt < GAME_MAP_BUN_YOKO_CNT_MAX*GAME_MAP_BUN_TATE_CNT_MAX; cnt++)
	{
		//�摜�T�C�Y���擾
		GetGraphSize(
			c->Handle[cnt],		//�n���h������A�摜�̕��ƍ������擾��
			&c->Width[cnt],		//MAP�\���̂̕��ɁA�摜�̕���ݒ肷��
			&c->Height[cnt]);	//MAP�\���̂̍����ɁA��m�̍�����ݒ肷��

		c->C_Width[cnt] = c->Width[cnt] / 2;	//�摜�̉��T�C�Y�̒��S�ʒu���擾
		c->C_Height[cnt] = c->Width[cnt] / 2;	//�摜�̏c�T�C�Y�̒��S�ʒu���擾
	}

	return TRUE;
}

//########## �}�b�v��(��)����̎�ނ̐ݒ������ ########
BOOL MY_MAP_READ_CSV_UE_KIND_SET(MAP *mapdata)
{
	int Soeji;

	//�ʍs�ł���}�b�v
	Soeji = 0;
	mapdata->mapOKKind[Soeji++] = 149;	//�K�i
	mapdata->mapOKKind[Soeji++] = 150;	//�K�i
	mapdata->mapOKKind[Soeji++] = 151;	//�K�i
	mapdata->mapOKKind[Soeji++] = 165;	//�K�i
	mapdata->mapOKKind[Soeji++] = 166;	//�K�i
	mapdata->mapOKKind[Soeji++] = 167;	//�K�i
	mapdata->mapOKKind[Soeji++] = 181;	//�K�i
	mapdata->mapOKKind[Soeji++] = 182;	//�K�i
	mapdata->mapOKKind[Soeji++] = 183;	//�K�i
	//�ʍs�ł����ނ̎c���-1�Ŗ��߂�
	Soeji = 0;
	for (int cnt = Soeji; cnt < GAME_MAP_OK_KIND; cnt++)
	{
		mapdata->mapOKKind[cnt] = -1;
	}

	//�ʍs�ł��Ȃ���ނ̎c���-1�Ŗ��߂�
	Soeji = 0;
	for (int cnt = Soeji; cnt < GAME_MAP_NG_KIND; cnt++)
	{
		mapdata->mapNGKind[cnt] = -1;
	}

	return TRUE;
}

//########## �}�b�v(��)����̎�ނ�ݒ肷�� ###########
BOOL MY_MAP_READ_CSV_NAKA_KIND_SET(MAP *mapdata)
{
	int Soeji;

	//�ʍs�ł����ނ̎c���-1�Ŗ��߂�
	Soeji = 0;
	for (int cnt = Soeji; cnt < GAME_MAP_OK_KIND; cnt++)
	{
		mapdata->mapOKKind[cnt] = -1;
	}


	//�ʍs�ł��Ȃ��}�b�v
	Soeji = 0;
	mapdata->mapNGKind[Soeji++] = 0;
	mapdata->mapNGKind[Soeji++] = 1;
	mapdata->mapNGKind[Soeji++] = 2;
	mapdata->mapNGKind[Soeji++] = 8;
	mapdata->mapNGKind[Soeji++] = 9;
	mapdata->mapNGKind[Soeji++] = 10;
	mapdata->mapNGKind[Soeji++] = 16;
	mapdata->mapNGKind[Soeji++] = 17;
	mapdata->mapNGKind[Soeji++] = 18;
	mapdata->mapNGKind[Soeji++] = 24;
	mapdata->mapNGKind[Soeji++] = 25;
	mapdata->mapNGKind[Soeji++] = 26;

	//�ʍs�ł��Ȃ���ނ̎c���-1�Ŗ��߂�
	for (int cnt = Soeji; cnt < GAME_MAP_NG_KIND; cnt++)
	{
		mapdata->mapNGKind[cnt] = -1;
	}

	return TRUE;
}

//########## �}�b�v(��)����̎�ނ�ݒ肷�� ########
BOOL MY_MAP_READ_CSV_SITA_KIND_SET(MAP *mapdata)

{
	int Soeji;

	//�ʍs�ł���}�b�v
	Soeji = 0;
	mapdata->mapOKKind[Soeji++] = 0;

	//�ʍs�ł����ނ̎c���-1�Ŗ��߂�
	Soeji = 0;
	for (int cnt = Soeji; cnt < GAME_MAP_OK_KIND; cnt++)
	{
		mapdata->mapOKKind[cnt] = -1;
	}

	//�ʍs�ł��Ȃ���ނ̎c���-1�Ŗ��߂�
	Soeji = 0;
	for (int cnt = Soeji; cnt < GAME_MAP_NG_KIND; cnt++)
	{
		mapdata->mapNGKind[cnt] = -1;
	}

	return TRUE;
}


//########## �Q�[���}�b�v��CSV��ǂݍ��ފ֐� ##########
BOOL MY_MAP_READ_CSV_NUM(MAP *mapdata, const char *path,const char *mapname)
{

	FILE  *fp;

	if ((fp = fopen(path, "r")) == NULL)	//�t�@�C����ǂݍ��݃��[�h(r)�ŊJ��
	{
		return FALSE;
	}//�ُ�I��	

	 //�������琳��ɓǂݍ��߂��Ƃ��̏���****************************************

	int result = 0;			//�t�@�C���̍Ōォ�`�F�b�N
	int LoopCnt = 0;		//���[�v�J�E���^
							
	//�t�@�C�����琔�l����ǂݍ���(%d,)�A�z��Ɋi�[����
	while (fscanf(fp, "%d,", &mapdata->data[LoopCnt / GAME_MAP_YOKO][LoopCnt % GAME_MAP_YOKO]) != EOF)	//End Of File�i�t�@�C���̍Ō�j�ł͂Ȃ��Ƃ��J��Ԃ�
	{
		mapdata->mapdate_Init[LoopCnt / GAME_MAP_YOKO][LoopCnt%GAME_MAP_YOKO]
			= mapdata->data[LoopCnt / GAME_MAP_YOKO][LoopCnt%GAME_MAP_YOKO];  //�l���R�s�[

		LoopCnt++;
	}
	fclose(fp);	//�t�@�C�������

	wsprintf(mapdata->name, mapname); //�}�b�v�̖��̂��R�s�[

	
	

	return TRUE;
}





//########## �}�b�v��\������֐� ##########
VOID MY_PLAY_MAP_DRAW(MAP MapImage)
{
	//�X�N���[������}�b�v��`��
	for (int tate = 0; tate < GAME_MAP_TATE; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO; yoko++)
		{
			if ((yoko + 1) * GAME_MAP_YOKO_SIZE - ScrollCntYoko >= 0 &&
				(yoko + 0) * GAME_MAP_YOKO_SIZE - ScrollCntYoko <= GAME_WIDTH &&	//��ʂɎʂ��Ă���Ȃ�΂Ȃ��
				(tate + 1) * GAME_MAP_TATE_SIZE - ScrollCntTate >= 0 &&
				(tate + 0) * GAME_MAP_TATE_SIZE - ScrollCntTate <= GAME_HEIGHT
				) //��ʂɎʂ��Ă���Ȃ��
			{
				DrawGraph(
					yoko * GAME_MAP_YOKO_SIZE - ScrollCntYoko,			//�ʒu����X�N���[���ʂ�����
					tate * GAME_MAP_TATE_SIZE - ScrollCntTate,
					MapImage.Handle[MapImage.data[tate][yoko]], TRUE);	//�}�b�v���X�N���[�����Ȃ���`��


			}
		}
	}
}



//######### �v���C���[��\������֐� ###########
VOID MY_PLAY_PLAYER_DRAW(CHARADATA player)
{
	//�v���C���[��`��	
	DrawGraph(
		player.X,
		player.Y,
		player.Handle[player.NowHandleNum], TRUE);


	if (AllKeyState[KEY_INPUT_LEFT] != 0)    //�����L�[��������Ă�����
	{
		if (Myplayer.NowHandleCnt < Myplayer.NowHandleCntMAX)
		{
			Myplayer.NowHandleCnt++;
		}
		else
		{
			Myplayer.NowHandleCnt = 0;

			if (Myplayer.NowHandleNum >= 9 && Myplayer.NowHandleNum < 11)
			{
				Myplayer.NowHandleNum++;	//���̍������̉摜
			}
			else
			{
				Myplayer.NowHandleNum = 9; //��ԍŏ��̍������̉摜
			}
		}
	}

	else if (AllKeyState[KEY_INPUT_RIGHT] != 0)  //�E���L�[��������Ă���Ƃ�
	{
		if (Myplayer.NowHandleCnt < Myplayer.NowHandleCntMAX)
		{
			Myplayer.NowHandleCnt++;
		}
		else
		{
			Myplayer.NowHandleCnt = 0;

			if (Myplayer.NowHandleNum >= 3 && Myplayer.NowHandleNum < 5)
			{
				Myplayer.NowHandleNum++;	//���̉E�����̉摜
			}
			else
			{
				Myplayer.NowHandleNum = 3; //��ԍŏ��̉E�����̉摜
			}
		}
	}

	else if (AllKeyState[KEY_INPUT_UP] != 0)	//����L�[��������Ă���Ƃ�
	{
		if (Myplayer.NowHandleCnt < Myplayer.NowHandleCntMAX)
		{
			Myplayer.NowHandleCnt++;
		}
		else
		{
			Myplayer.NowHandleCnt = 0;

			if (Myplayer.NowHandleNum >= 0 && Myplayer.NowHandleNum < 2)
			{
				Myplayer.NowHandleNum++;	//���̏�����̉摜
			}
			else
			{
				Myplayer.NowHandleNum = 0; //��ԍŏ��̏�����̉摜
			}
		}
	}

	else if (AllKeyState[KEY_INPUT_DOWN] != 0)
	{
		if (Myplayer.NowHandleCnt < Myplayer.NowHandleCntMAX)
		{
			Myplayer.NowHandleCnt++;
		}
		else
		{
			Myplayer.NowHandleCnt = 0;

			if (Myplayer.NowHandleNum >= 6 && Myplayer.NowHandleNum < 8)
			{
				Myplayer.NowHandleNum++;	//���̍������̉摜
			}
			else
			{
				Myplayer.NowHandleNum = 6; //��ԍŏ��̍������̉摜
			}
		}
	}
	return;
}


//######### �E�B���h�E�v���V�[�W���֐� ############
LRESULT CALLBACK MY_WNDPROC(HWND hwnd, UINT mgs, WPARAM wp, LPARAM lp)
{
	switch (mgs)
	{

	case WM_CREATE:	//�E�B���h�E�̐�����������

		IsWM_CREATE = TRUE;	//WM_CREATE����I��

		return 0;

	case WM_CLOSE:	//����{�^�����������Ƃ�

		MessageBox(hwnd, TEXT("�Q�[�����I�����܂��B"), TEXT("�I�����b�Z�[�W"), MB_OK);
		break;

	case WM_RBUTTONDOWN:	//�}�E�X�̉E�{�^�����������Ƃ�

		SendMessage(hwnd, WM_CLOSE, 0, 0);	//WM_CLOSE���b�Z�[�W�L���[�ɒǉ�
		break;

	case WM_LBUTTONDOWN:

		PostMessage(hwnd, WM_NCLBUTTONDOWN, (WPARAM)HTCAPTION, lp);		//WM_NCLBUTTONDOWN(�^�C�g���o�[�Ń}�E�X�̍��{�^����������)
		break;

	case WM_ACTIVATE:

		if (IsActiveCheck == TRUE)	//��ʂ̃A�N�e�B�u�`�F�b�N�̗L����
		{
			switch (wp)
			{
			case WA_INACTIVE:	//��A�N�e�B�u��

				StopActiveStartTime = GetNowCount();

				break;

			case WA_ACTIVE:	//�L�[�{�[�h�ȂǂŃA�N�e�B�u��

				StopActiveStartTime = GetNowCount();

				break;

			case WA_CLICKACTIVE:

				StopActiveStopTime = GetNowCount();

				break;

			default:

				break;
			}
		}
		return 0;

	case WM_DESTROY:	//�E�B���h�E���j�����ꂽ�Ƃ�

		PostQuitMessage(0);	//���b�Z�[�W�L���[�� WM_QUIT �𑗂�
		return 0;
	}

	//�f�t�H���g�̃E�B���h�E�v���V�[�W���֐����Ăяo��
	return DefWindowProc(hwnd, mgs, wp, lp);
}