
#include "DxLib.h"


#define GAME_WIDTH 800		//画面の横幅
#define GAME_HEIGHT 600		//画面の縦幅
#define GAME_COLOR 32		//使用する画面の色の数



#define GAME_WINDOW_NAME "GAME_TITLE"
#define GAME_WINDOW_MODECHANGE	TRUE

#define GAME_FPS_SPEED                       60		//FPS数

#define SET_WINDOW_ST_MODE_DEFAULT          0
#define SET_WINDOW_ST_MODE_TITLE_NON        1
#define SET_WINDOW_ST_MODE_TITLE_FLAME_NONE 2
#define SET_WINDOW_ST_MODE_FLAME_NONE		3

#define GAME_TITLEIMAGE "TITLEIMAGE\\Title.png"						//タイトル画像
#define GAME_TITLE_BACKIMAGE "BACKIMAGE\\TITLE_BACK.jpg"			//タイトル背景画像

#define GAME_PROLOGUE "BACKIMAGE\\PROLOGUE.jpg"							//プロローグ


#define GAME_MAP_1 "GAME_MAP\\A2.png"           //マップチップの画像
#define GAME_MAP_2 "GAME_MAP\\Cave1-EarthA5.png"
#define GAME_MAP_3 "GAME_MAP\\Cave1-RockA5.png"
#define GAME_MAP_4 "GAME_MAP\\Ruin-F.png"

//マップのcsv
#define GAME_MAP_CSV_1 "GAME_MAP\\F1.csv"				//1階
#define GAME_MAP_CSV_2 "GAME_MAP\\F2.csv"				//2階
#define GAME_MAP_CSV_3 "GAME_MAP\\F3.csv"				//3階
#define GAME_MAP_CSV_4 "GAME_MAP\\F4.csv"				//4階
#define GAME_MAP_CSV_5 "GAME_MAP\\Boss.csv"				//ボス
#define GAME_MAP_CSV_6 "GAME_MAP\\map_under.csv"		//map下地
#define GAME_MAP_CSV_7 "GAME_MAP\\Bossmap_under.csv"	//ボスmap下地
#define GAME_MAP_CSV_1_K "GAME_MAP\\kaidan.csv"			//1階の階段
#define GAME_MAP_CSV_2_K "GAME_MAP\\kaidan2.csv"		//2階の階段
#define GAME_MAP_CSV_3_K "GAME_MAP\\kaidan3.csv"		//3階の階段
#define GAME_MAP_CSV_4_K "GAME_MAP\\kaidan4.csv"		//4階の階段

//マップの名称
#define GAME_MAP_NAME_SITA		"MAPDATA_SITA"
#define GAME_MAP_F1				"MAPDATA_F1"
#define GAME_MAP_F2				"MAPDATA_F2"
#define GAME_MAP_F3				"MAPDATA_F3"
#define GAME_MAP_F4				"MAPDATA_F4"
#define GAME_MAP_F1_K			"MAPDATA_F1_KAIDAN"
#define GAME_MAP_BOSS_SITA		"MAPDATA_BOSS_UNDER"
#define GAME_MAP_BOSS			"MAPDATA_BOSS"

#define GAME_MAP_BUN_YOKO_CNT_MAX 16		//各マップチップの横の最大分割数
#define GAME_MAP_BUN_TATE_CNT_MAX 16		//各マップチップの縦の最大分割数

#define GAME_MAP_1_YOKO_MAX 16		//GAME_MAP_1の横の最大分割数
#define GAME_MAP_1_TATE_MAX 12		//GAME_MAP_1の縦の最大分割数

#define GAME_MAP_2_YOKO_MAX 8		//GAME_MAP_2の横の最大分割数
#define GAME_MAP_2_TATE_MAX 16	    //GAME_MAP_2の縦の最大分割数

#define GAME_MAP_3_YOKO_MAX 8		//GAME_MAP_3の横の最大分割数
#define GAME_MAP_3_TATE_MAX 16	    //GAME_MAP_3の縦の最大分割数

#define GAME_MAP_4_YOKO_MAX 16		//GAME_MAP_4の横の最大分割数
#define GAME_MAP_4_TATE_MAX 16	    //GAME_MAP_4の縦の最大分割数

#define GAME_MAP_YOKO 50		//ゲームマップの横サイズ
#define GAME_MAP_TATE 38		//ゲームマップの縦サイズ

#define GAME_MAP_YOKO_SIZE 32	//ゲームマップの1マスのサイズ
#define GAME_MAP_TATE_SIZE 32

#define GAME_MAP_OK_KIND 100 //通行できるマップの種類
#define GAME_MAP_NG_KIND 100 //通行できないマップの種類

#define GAME_CHARA                "CHARAIMAGE\\char_p04.png"  //キャラの画像
#define GAME_CHARA_BUN_YOKO_CNT 12		//キャラの分割数(横)
#define GAME_CHARA_BUN_TATE_CNT 8       //キャラの分割数(縦)
#define GAME_CHARA_YOKO_SIZE 24			//キャラの大きさ(横)
#define GAME_CHARA_TATE_SIZE 32			//キャラの大きさ(縦)
#define GAME_CHARA_MOTION_NUM 12		//キャラの画像数
#define GAME_CHARA_KIND_YOKO 3		//キャラの横の種類
#define GAME_CHARA_KIND_TATE 4		//キャラの縦の種類

#define GAME_CHARA_START_X 5	    //キャラの最初の位置
#define GAME_CHARA_START_Y 1       //キャラの最初の位置
#define GAME_CHARA_SPEED 2         //キャラのスピード

//#######列挙型#########

enum GAME_SCENE {
	GAME_SCENE_TITLE,	//タイトル画面
	GAME_SCENE_PUOLOGUE,	//プロローグ画面
	GAME_SCENE_PLAY,	//プレイ画面
//	GAME_SCENE_GAMEOVER,	//GameOver画面
	GAME_SCENE_END		//エンド画面
};

enum CHARA_IMAGE {
	CHARA_KIND_1 = 0,
	CHARA_KIND_2 = 3,
	CHARA_KIND_3 = 6,
	CHARA_KIND_4 = 9,
	CHARA_KIND_5 = 54
}; //キャラの種類の列挙型

struct STRUCT_GAZOU {
	int Handle;			//画像のハンドル
	char FilePath[128];	//ファイルのパス
	int X;				//横の位置
	int Y;				//縦の位置
	int Width;			//横のサイズ
	int Height;			//縦のサイズ
	int C_Width;		//横の中心位置
	int C_Height;		//縦の中心位置
}; //画像構造体

struct STRUCT_IMAGE
{
	char FilePath[128];												//ファイルのパス
	int Handle[GAME_MAP_BUN_YOKO_CNT_MAX * GAME_MAP_BUN_TATE_CNT_MAX];		//画像のハンドル
	int X[GAME_MAP_BUN_YOKO_CNT_MAX * GAME_MAP_BUN_TATE_CNT_MAX];			//横の位置
	int Y[GAME_MAP_BUN_YOKO_CNT_MAX * GAME_MAP_BUN_TATE_CNT_MAX];			//縦の位置
	int Width[GAME_MAP_BUN_YOKO_CNT_MAX * GAME_MAP_BUN_TATE_CNT_MAX];		//横のサイズ
	int Height[GAME_MAP_BUN_YOKO_CNT_MAX * GAME_MAP_BUN_TATE_CNT_MAX];		//縦のサイズ
	int C_Width[GAME_MAP_BUN_YOKO_CNT_MAX * GAME_MAP_BUN_TATE_CNT_MAX];		//横の中心位置
	int C_Height[GAME_MAP_BUN_YOKO_CNT_MAX * GAME_MAP_BUN_TATE_CNT_MAX];	//縦の中心位置

};	//STRUCT_IMAGE構造体

struct STRUCT_MAP
{
	char name[64];	//マップの名称
	char FilePath[128];		//ファイルのパス
	int data[GAME_MAP_TATE][GAME_MAP_YOKO];	//マップのCSVのデータ
	int mapdate_Init[GAME_MAP_TATE][GAME_MAP_YOKO];	//マップのCSVデータ

	int Handle[GAME_MAP_BUN_YOKO_CNT_MAX*GAME_MAP_BUN_TATE_CNT_MAX];  //画像のハンドル
	int X[GAME_MAP_BUN_YOKO_CNT_MAX*GAME_MAP_BUN_TATE_CNT_MAX];		//横の位置
	int Y[GAME_MAP_BUN_YOKO_CNT_MAX*GAME_MAP_BUN_TATE_CNT_MAX];		//縦の位置
	int Width[GAME_MAP_BUN_YOKO_CNT_MAX*GAME_MAP_BUN_TATE_CNT_MAX];	//横のサイズ
	int Height[GAME_MAP_BUN_YOKO_CNT_MAX*GAME_MAP_BUN_TATE_CNT_MAX];  //縦のサイズ
	int C_Width[GAME_MAP_BUN_YOKO_CNT_MAX*GAME_MAP_BUN_TATE_CNT_MAX]; //横の中心位置
	int C_Height[GAME_MAP_BUN_YOKO_CNT_MAX*GAME_MAP_BUN_TATE_CNT_MAX]; //縦の中心位置

	int mapNGKind[GAME_MAP_NG_KIND];					//マップ判定の種類(通行できない)
	int mapOKKind[GAME_MAP_OK_KIND];					//マップ判定の種類(通行できる)

	RECT rect_NG[GAME_MAP_TATE][GAME_MAP_YOKO];			//当たり判定の領域(通行できない)
	RECT rect_NG_First[GAME_MAP_TATE][GAME_MAP_YOKO];	//当たり判定の領域(通行できない)(最初)

	RECT rect_OK[GAME_MAP_TATE][GAME_MAP_YOKO];			//当たり判定の領域(通行できる)
	RECT rect_OK_First[GAME_MAP_TATE][GAME_MAP_YOKO];	//当たり判定の領域(通行できる)(最初)

}; //MAP構造体

struct STRUCT_CHARAIMAGE
{
	char FilePath[128];												//ファイルのパス
	int Handle[GAME_CHARA_BUN_YOKO_CNT*GAME_CHARA_BUN_TATE_CNT];	//画像のハンドル
	int X[GAME_CHARA_BUN_YOKO_CNT*GAME_CHARA_BUN_TATE_CNT];			//横の位置
	int Y[GAME_CHARA_BUN_YOKO_CNT*GAME_CHARA_BUN_TATE_CNT];			//縦の位置
	int Width[GAME_CHARA_BUN_YOKO_CNT*GAME_CHARA_BUN_TATE_CNT];		//縦のサイズ
	int Height[GAME_CHARA_BUN_YOKO_CNT*GAME_CHARA_BUN_TATE_CNT];	//横のサイズ
	int C_Width[GAME_CHARA_BUN_YOKO_CNT*GAME_CHARA_BUN_TATE_CNT];	//横の中心位置
	int C_Height[GAME_CHARA_BUN_YOKO_CNT*GAME_CHARA_BUN_TATE_CNT];	//縦の中心位置
}; //STRUCT_CHARAIMAGE構造体

struct STRUCT_CHARADATA
{
	STRUCT_CHARAIMAGE charimage;	//画像
	int Handle[GAME_CHARA_MOTION_NUM];//画像のハンドル
	int X;							//縦の位置
	int Y;							//横の位置
	int Width;						//横のサイズ
	int Height;						//縦のサイズ
	int C_Width;					//横の中心位置
	int C_Height;					//縦の中心位置
	int NowHandleNum;				//現在の画像のハンドル
	int NowHandleCnt;				//現在のハンドルカウント
	int NowHandleCntMAX;			//現在のハンドルカウントMAX

	int Speed;						//速度
	int MoveDistX;					//移動距離X
	int MoveDistY;					//移動距離Y

	BOOL CanMoveUp;					//上に行けるか
	BOOL CanMoveDown;				//下の行けるか
	BOOL CanMoveLeft;				//左の行けるか
	BOOL CanMoveRight;				//右に行けるか

	BOOL ScrollOK_X;				//スクロールできるかどうか
	BOOL ScrollOK_Y;

	int atariX;			//当たり判定のX位置
	int atariY;			//当たり判定のY位置
	int atariWidth;		//当たり判定の幅
	int atariHeight;	//当たり判定の高さ	
	RECT atariRect;		//当たり判定の矩形領域

	char name[255];		//名前


	RECT rect_act;	//行動の領域

	int act_kind;				//行動の種類
	BOOL IsActKeyDown_left;		//行動を押したとき(右)
	BOOL IsActKeyDown_right;	//行動を押したとき(左)

}; //STRUCT_CHARADATA構造体

//###### 名前の再定義 ########
typedef STRUCT_GAZOU GAZOU;
typedef STRUCT_IMAGE IMAGE;
typedef STRUCT_MAP MAP;
typedef STRUCT_CHARAIMAGE CHARAIMAGE;
typedef STRUCT_CHARADATA CHARADATA;

GAZOU  BackGround;	//タイトル背景画像
GAZOU  BackGround_T;  //タイトル画像
GAZOU  BackGround_P;	//プロローグ

MAP MapImage;
MAP MapImage_U;  //下地のマップ画像
MAP MapImage_W;  //壁などのマップ画像
MAP MapImage_B;  //ボス面のマップ画像
MAP MapImage_S;  //階段のマップ画像

//######### グローバル変数 #######

//ウィンドウ関係
WNDPROC WndProc;			//ウィンドウプロシージャのアドレス
BOOL IsWM_CREATE = FALSE;   //WM_CREATEが正常に起動したか判断する

//FPS関連
int StartTimeFps;					//測定開始時刻
int CountFps;						//カウンタ
float CalcFps;						//計算結果
int SampleNumFps = GAME_FPS_SPEED;  //平均を取るサンプル

//キーボード関係
char AllKeyState[256];	//すべてのキーの状態が入る

//シーン関係
int GameSceneNow = (int)GAME_SCENE_TITLE;	//最初のゲーム画面をタイトル画面に設定

//キャラ系
CHARAIMAGE CharaImage;		//キャラの画像
CHARADATA  Myplayer;		//キャラのデータ


//プレイヤーのイメージ画像の番号を設定する
int PlayerImageNum[GAME_CHARA_MOTION_NUM];

int ScrollCntYoko = 0;	//スクロールカウンタ(横)
int ScrollDistPlusYoko = 1;  //スクロールする距離(横)


int ScrollCntTate = 0;  //スクロールカウンタ(縦)
int ScrollDistPlusTate = 1;  //スクロールする距離(縦)

BOOL IsActiveCheck = FALSE;	//画面のアクティブチェックの有効化

int StopActiveStartTime = 0;	//非アクティブ化の開始時間
int StopActiveStopTime = 0;		//非アクティブ化の終了時間
int StopActiveTotaTime = 0;		//非アクティブ化の経過時間

//####### プロトタイプ宣言 ##########
LRESULT CALLBACK MY_WNDPROC(HWND, UINT, WPARAM, LPARAM); //自作ウィンドウプロシージャ

VOID MY_FPS_UPDATE(VOID);		//FPS値を計測、更新をする関数
VOID MY_FPS_DRAW(VOID);			//FPS値を描画する関数
VOID MY_FPS_WAIT(VOID);			//FPS値を計測し、待つ関数

VOID MY_ALL_KEYDOWN_UPDATE(VOID);	//キー入力状態を更新する関数

VOID MY_GAME_TITLE(VOID);		//タイトル画面
VOID MY_GAME_PROLOGUE(VOID);	//プロローグ画面
VOID MY_GAME_PLAY(VOID);		//プレイ画面
VOID MY_GAME_END(VOID);			//エンド画面

VOID MY_PLAY_MAP_DRAW(MAP);			//マップを表示する関数
VOID MY_PLAY_MAP_DRAW_ATARI(MAP *, MAP *, MAP *);		//マップの当たり判定を描画する関数
BOOL MY_GAZOU_LOAD(GAZOU *, int, int, const char *);			//画像を読み込む設定をする関数

BOOL MY_PLAY_INIT(VOID);	//初期化関数

BOOL MY_MAP_READ_CSV_UE_KIND_SET(MAP *);	//マップ判定の種類を設定する(上)
BOOL MY_MAP_READ_CSV_NAKA_KIND_SET(MAP *);	//マップ判定の種類を設定する(中)
BOOL MY_MAP_READ_CSV_SITA_KIND_SET(MAP *);	//マップ判定の種類を設定する(下)
BOOL MY_MAP_READ_CSV_NUM(MAP * ,const char *, const char *);			//ゲームマップのF1CSVを読み込む関数

BOOL MY_MAP_LOAD_BUNKATSU(MAP *, int, int, int, int, int, const char *);	//MAPを分割して読み込む設定をする関数
BOOL MY_MAP_2_LOAD_BUNKATSU(MAP *, int, int, int, int, int, const char *);	//MAPを分割して読み込む設定をする関数
BOOL MY_MAP_3_LOAD_BUNKATSU(MAP *, int, int, int, int, int, const char *);	//MAPを分割して読み込む設定をする関数
BOOL MY_MAP_4_LOAD_BUNKATSU(MAP *, int, int, int, int, int, const char *);	//MAPを分割して読み込む設定をする関数

BOOL MY_CHARA_LOAD_BUNKATSU(CHARAIMAGE *,int,int,int,int,int, const char *);

BOOL MY_PLAYER_INIT(CHARADATA *, CHARAIMAGE, int *, int, int, int);	//プレイヤーを初期化する関数
VOID MY_PLAY_PLAYER_DRAW(CHARADATA);	//プレイヤーを表示する関数

VOID MY_PLAY_PLAYER_OPERATION(VOID);						//プレイヤーを操作する関数
BOOL MY_PLAY_PLAYER_OPERATION_KEY(int *, int *);			//プレイヤーをキー操作する関数

VOID MY_SET_PLAYER_ATARI(CHARADATA *);			//プレイヤーの当たり判定の領域を設定する関数

BOOL MY_CHECK_RECT_ATARI(RECT, RECT);		//領域の当たり判定をする関数
BOOL MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(RECT, RECT map[GAME_MAP_TATE][GAME_MAP_YOKO], int *, int *);

int MapData[GAME_MAP_TATE][GAME_MAP_YOKO];  //マップのデータfp
FILE *fp_map_csv;  //ファイルの管理番号(ポインタ)
int MapData_Init[GAME_MAP_TATE][GAME_MAP_YOKO]; //マップのデータ(初期化用)

//############ プログラムで最初に実行される関数 ###########
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	ChangeWindowMode(TRUE);								//ウィンドウモードに設定
	SetGraphMode(GAME_WIDTH, GAME_HEIGHT, GAME_COLOR); //指定の数値で画面を表示する

	SetWindowStyleMode(SET_WINDOW_ST_MODE_DEFAULT);		//タイトルバーあり

	SetMainWindowText(TEXT(GAME_WINDOW_NAME));			//タイトル文字

	if (DxLib_Init() == -1) {			//DXライブラリ初期化処理
		return -1;
	}

	SetDrawScreen(DX_SCREEN_BACK);		//Drow系関数は裏画面に表示

	MY_MAP_READ_CSV_UE_KIND_SET(&MapImage_S);	//マップの上の種類を設定
	MY_MAP_READ_CSV_NAKA_KIND_SET(&MapImage_W);	//マップの中の種類を設定
	MY_MAP_READ_CSV_SITA_KIND_SET(&MapImage_U);	//マップの下の種類を設定

	if (MY_GAZOU_LOAD(&BackGround, 0, 0, GAME_TITLE_BACKIMAGE) == FALSE) {  //タイトル背景画像を読み込む
		MessageBox(NULL, GAME_TITLE_BACKIMAGE, "NotFound", MB_OK);
		return -1;
	}


	if (MY_GAZOU_LOAD(&BackGround_T,150,200, GAME_TITLEIMAGE) == FALSE) {  //タイトル画像を読み込む
		MessageBox(NULL, GAME_TITLEIMAGE, "NotFound", MB_OK);
		return -1;
	}

	if (MY_GAZOU_LOAD(&BackGround_P, 0, 0, GAME_PROLOGUE) == FALSE) {  //プロローグ画像を読み込む
		MessageBox(NULL, GAME_PROLOGUE, "NotFound", MB_OK);
		return -1;
	}

	if (MY_MAP_LOAD_BUNKATSU(&MapImage_U, GAME_MAP_1_YOKO_MAX * GAME_MAP_1_TATE_MAX, GAME_MAP_1_YOKO_MAX, GAME_MAP_1_TATE_MAX,  GAME_MAP_YOKO_SIZE, GAME_MAP_TATE_SIZE, GAME_MAP_1) == FALSE) {  //下地のマップチップ画像を読み込む
		MessageBox(NULL, GAME_MAP_1, "NotFound", MB_OK);
		return -1;
	}

	if (MY_MAP_2_LOAD_BUNKATSU(&MapImage_W, GAME_MAP_2_YOKO_MAX * GAME_MAP_2_TATE_MAX, GAME_MAP_2_YOKO_MAX, GAME_MAP_2_TATE_MAX, GAME_MAP_YOKO_SIZE, GAME_MAP_TATE_SIZE, GAME_MAP_2) == FALSE) {  //壁系のマップチップ画像を読み込む
		MessageBox(NULL, GAME_MAP_2, "NotFound", MB_OK);
		return -1;
	}

	if (MY_MAP_3_LOAD_BUNKATSU(&MapImage_B, GAME_MAP_3_YOKO_MAX*GAME_MAP_3_TATE_MAX, GAME_MAP_3_YOKO_MAX, GAME_MAP_3_TATE_MAX, GAME_MAP_YOKO_SIZE, GAME_MAP_TATE_SIZE, GAME_MAP_3) == FALSE) {  //ボスエリアのマップチップを読み込む
		MessageBox(NULL, GAME_MAP_3, "NotFound", MB_OK);
		return -1;
	}

	if (MY_MAP_4_LOAD_BUNKATSU(&MapImage_S, GAME_MAP_4_YOKO_MAX*GAME_MAP_4_TATE_MAX, GAME_MAP_4_YOKO_MAX, GAME_MAP_4_TATE_MAX, GAME_MAP_YOKO_SIZE, GAME_MAP_TATE_SIZE, GAME_MAP_4) == FALSE) {  //階段のマップチップを読み込む
		MessageBox(NULL, GAME_MAP_4, "NotFound", MB_OK);
		return -1;
	}

	if (MY_CHARA_LOAD_BUNKATSU(&CharaImage, GAME_CHARA_BUN_YOKO_CNT*GAME_CHARA_BUN_TATE_CNT, GAME_CHARA_BUN_YOKO_CNT, GAME_CHARA_BUN_TATE_CNT, GAME_CHARA_YOKO_SIZE, GAME_CHARA_TATE_SIZE, GAME_CHARA) == FALSE) {
		MessageBox(NULL, GAME_CHARA, "NotFound", MB_OK);
		return -1;
	}		//GAME_CHARAを読み込む

	MY_MAP_READ_CSV_NUM(&MapImage_W, GAME_MAP_CSV_1, GAME_MAP_F1);		    //マップ１の上を読み込み、当たり判定の領域をつくる
	MY_MAP_READ_CSV_NUM(&MapImage_S, GAME_MAP_CSV_1_K, GAME_MAP_F1_K);		//マップ１の階段を読み込み、当たり判定の領域をつくる
	MY_MAP_READ_CSV_NUM(&MapImage_U, GAME_MAP_CSV_6, GAME_MAP_NAME_SITA);	//マップ１の下を読み込み、当たり判定の領域をつくる

	IsActiveCheck = TRUE;

	while (TRUE)		//無限ループ
	{
		if (ProcessMessage() != 0)	//メッセージ処理の結果がエラーのとき、強制終了
		{
			break;
		}

		if (ClearDrawScreen() != 0) {	//画面を消去できなかった時、強制終了
			break;
		}

        MY_ALL_KEYDOWN_UPDATE();		//キーの状態を取得

		switch (GameSceneNow)	//シーン選択
		{
		case(int)GAME_SCENE_TITLE:	//タイトル画面の処理ここから

			MY_GAME_TITLE();	//タイトル画面の処理

			break;	//タイトル画面の処理ここまで
		

		case(int)GAME_SCENE_PUOLOGUE:	//プロローグ画面の処理ここから

			MY_GAME_PROLOGUE();	//プロローグ画面の処理

			break;	//プロローグ画面の処理ここまで

		case (int)GAME_SCENE_PLAY:	//プレイ画面の処理ここから

			MY_GAME_PLAY();	//プレイ画面の処理

			break;	//プレイ画面の処理ここまで

		case (int)GAME_SCENE_END:	//エンド画面の処理ここから

			MY_GAME_END();	//エンド画面の処理

			break;	//エンド画面の処理ここまで

		default:

			break;
		}
		MY_FPS_UPDATE();		//FPSの処理(更新)
		
		MY_FPS_DRAW();			//FPSの処理(描画)

		ScreenFlip();			//モニタのリフレッシュレートの速さで裏画面を再描画

		MY_FPS_WAIT();			//FPSの処理(待つ)

	}

	DeleteGraph(BackGround.Handle);	//背景のハンドルを削除

	DeleteGraph(BackGround_T.Handle);	//タイトル画像のハンドルを削除

	DeleteGraph(BackGround_P.Handle);	//プロローグ画像のハンドルを削除

	for (int mapCnt = 0; mapCnt < GAME_MAP_1_YOKO_MAX * GAME_MAP_1_TATE_MAX; mapCnt++)
	{
		DeleteGraph(MapImage_U.Handle[mapCnt]);	//マップ1のハンドルを削除
	}

	for (int mapCnt = 0; mapCnt < GAME_MAP_2_YOKO_MAX * GAME_MAP_2_TATE_MAX; mapCnt++)
	{
		DeleteGraph(MapImage_W.Handle[mapCnt]);	//マップ2のハンドルを削除
	}

	for (int mapCnt = 0; mapCnt < GAME_MAP_3_YOKO_MAX * GAME_MAP_3_TATE_MAX; mapCnt++)
	{
		DeleteGraph(MapImage_B.Handle[mapCnt]);	//マップ3のハンドルを削除
	}

	for (int mapCnt = 0; mapCnt < GAME_MAP_4_YOKO_MAX * GAME_MAP_4_TATE_MAX; mapCnt++)
	{
		DeleteGraph(MapImage_S.Handle[mapCnt]);	//マップ4のハンドルを削除
	}

	DxLib_End();	//DXライブラリ使用の終了処理

	return 0;
}


//###### FPS値を計測、更新する関数 #######
VOID MY_FPS_UPDATE(VOID)
{
	if (CountFps == 0)	 //1フレーム目なら時刻を記憶
	{
		StartTimeFps = GetNowCount();
	}

	if (CountFps == SampleNumFps)	//60フレーム目なら平均を計算
	{
		int now = GetNowCount();
		CalcFps = 1000.f / ((now - StartTimeFps) / (float)SampleNumFps);
		CountFps = 0;
		StartTimeFps = now;
	}
	CountFps++;
	return;
}

//########## FPS値を描画する関数 #########
VOID MY_FPS_DRAW(VOID)
{
	//文字列を描画
	DrawFormatString(0, GAME_HEIGHT - 20, GetColor(0, 0, 0), "FPS:%.1f", CalcFps);
	return;
}

//####### FPS値を計測し、待つ関数 #########
VOID MY_FPS_WAIT(VOID)
{
	int resultTime = GetNowCount() - StartTimeFps;	//かかった時間
	int waitTime = CountFps * 1000 / GAME_FPS_SPEED - resultTime;	//待つべき時間

	if (waitTime > 0)	//指定のFPS値よりも早い場合
	{
		Sleep(waitTime);	//待つ
	}
	return;

}

//####### キー入力状態を更新する関数 ######
VOID MY_ALL_KEYDOWN_UPDATE(VOID)
{
	char TempKey[256];	//一時的に、現在のキーの入力状態を格納する

	GetHitKeyStateAll(TempKey);	//すべてのキーの入力状態を得る

	for (int i = 0; i < 256; i++)
	{
		if (TempKey[i] != 0)	//押されているキーのキーコードを押しているとき
		{
			AllKeyState[i]++;	//押されている
		}
		else
		{
			AllKeyState[i] = 0;	//押されていない
		}
	}
	return;
}

//######## タイトル画面の関数 #############
VOID MY_GAME_TITLE(VOID)
{
	if (AllKeyState[KEY_INPUT_RETURN] != 0)
	{
		if (MY_PLAY_INIT() == TRUE)
		{
			GameSceneNow = (int)GAME_SCENE_PUOLOGUE;	//プロローグ画面に遷移
		}
	}


	DrawGraph( BackGround.X, BackGround.Y, BackGround.Handle, TRUE);		//タイトル背景画像描画

	DrawGraph(BackGround_T.X, BackGround_T.Y, BackGround_T.Handle, TRUE);		//タイトル画像描画

	DrawString(0, 0, "タイトル画面(エンターキーを押してください)", GetColor(0, 0, 0));
	return;
}


//####### プロローグ画面の関数 ############# 
VOID MY_GAME_PROLOGUE(VOID)
{
	if (AllKeyState[KEY_INPUT_SPACE] != 0)
	{
		GameSceneNow = (int)GAME_SCENE_PLAY;	//プレイ画面に遷移
	}

	DrawGraph(BackGround_P.X, BackGround_P.Y, BackGround_P.Handle, TRUE);	//プロローグ画像描画

	DrawString(0, 550, "SPACEでスキップ", GetColor(0, 0, 0));

	return;
}

//########### プレイ画面の関数 ############
VOID MY_GAME_PLAY(VOID)
{
	MY_PLAY_PLAYER_OPERATION();

	MY_PLAY_MAP_DRAW(MapImage_U);	//マップを描画

	MY_PLAY_MAP_DRAW(MapImage_S);	//マップを描画

	MY_PLAY_MAP_DRAW(MapImage_W);	//マップを描画

	MY_PLAY_PLAYER_DRAW(Myplayer);

	//MY_PLAY_MAP_DRAW_ATARI(&MapImage_W, &MapImage_W, &MapImage_U);

	DrawString(0, 0,"プレイ画面(Aキーを押してください)", GetColor(255, 255, 255));

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

	DrawString(0, 0, "エンド画面(バックスペースキーを押してください)", GetColor(255, 255, 255));

	return;
}

//########## 初期化関数 ##########
BOOL MY_PLAY_INIT(VOID)
{
	ScrollCntYoko = 0;	//スクロール量を初期化
	ScrollCntTate = 0;

	//プレイヤーの画像の番号を設定
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

	//プレイヤーを初期化
	if (MY_PLAYER_INIT(&Myplayer, CharaImage, &PlayerImageNum[0], GAME_MAP_YOKO_SIZE*GAME_CHARA_START_X, GAME_MAP_TATE_SIZE*GAME_CHARA_START_Y, GAME_CHARA_SPEED) == FALSE) {
		MessageBox(NULL, "CHARA_INIT", "NotFound", MB_OK);
		return FALSE;
	}


	return TRUE;
}

//########## プレイヤーを初期化する関数 ##########
//引　数：CHARADATA 構造体：設定するCHARADATA構造体
//引　数：CHARAIMAGE構造体：設定するCHARAIMAGE構造体
//引　数：int* 　　 　　　：使用する画像の番号（配列の先頭アドレスを引数とする）
//引　数：int　	　　　　　：画像の初期位置X
//引　数：int　	　　　　　：画像の初期位置Y
//引　数：int　	　　　　　：移動スピード
//戻り値：BOOL：エラー時：FALSE
BOOL MY_PLAYER_INIT(CHARADATA *charadata, CHARAIMAGE charaimage, int *num, int x, int y, int speed)
{
	//*(num+0)ば配列の先頭アドレス
	for (int mot = 0; mot < GAME_CHARA_MOTION_NUM; mot++)
	{
		charadata->Handle[mot] = charaimage.Handle[*(num + mot)];	//画像のハンドルを見る
	}

	charadata->X = x;
	charadata->Y = y;
	charadata->Width = charaimage.Width[*(num + 0)];      //最初の画像の横幅を設定する
	charadata->Height = charaimage.Height[*(num + 0)];	  //最初の画像の高さを設定する
	charadata->C_Width = charaimage.C_Width[*(num + 0)];  //最初の画像の横幅の中心を設定する
	charadata->C_Height = charaimage.C_Height[*(num + 0)]; //最初の画像の高さを設定する

	//マップ一つあたりと同じ大きさにする
	charadata->Width = GAME_MAP_YOKO_SIZE;
	charadata->Height = GAME_MAP_TATE_SIZE;
	charadata->C_Width = GAME_MAP_YOKO_SIZE / 2;
	charadata->C_Height = GAME_MAP_TATE_SIZE / 2;

	charadata->NowHandleNum = 6;	//前向きの最初の画像
	charadata->NowHandleCnt = 0;	//画像カウンタを初期化

	charadata->NowHandleCntMAX = 6; //画像カウンタMAXを初期化

	//*************  パラメータ設定  ********************************
	charadata->Speed = speed;

	charadata->MoveDistX = x;		//今の距離をマップの最初から動いた距離として設定する
	charadata->MoveDistY = y;		

	charadata->CanMoveUp = TRUE;		//上に移動できる
	charadata->CanMoveDown = TRUE;		//下に移動できる
	charadata->CanMoveLeft = TRUE;		//左に移動できる
	charadata->CanMoveRight = TRUE;		//右に移動できる

	charadata->ScrollOK_X = FALSE;	//移動できない
	charadata->ScrollOK_Y = FALSE;

	charadata->atariX = 4;				//当たり判定のX位置を丁度良く設定
	charadata->atariY = 10;				//当たり判定のY位置を丁度良く設定
	charadata->atariWidth = 18;			//当たり判定の幅を丁度良く設定
	charadata->atariHeight = 24;		//当たり判定の高さを丁度良く設定

	//wsprintf(charadata->name, GAME_PLAYER_NAME);

	MY_SET_PLAYER_ATARI(charadata);	//プレイヤーの当たり判定の領域を設定

	return TRUE;
}

//########## キャラクターとマップの当たり判定をする関数(当たった場所を知る) ##########
//引　数　：RECT	：当たり判定をする領域(キャラクター)
//引　数　：RECT	：当たり判定をする領域(マップ)
//引　数　：int 	：あたった場所(X位置)
//引　数　：int 	：あたった場所(Y位置)
//戻り値　：当たっている：TRUE / 当たっていない / FALSE
BOOL MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(RECT chara, RECT map[GAME_MAP_TATE][GAME_MAP_YOKO], int *atariX, int *atariY)
{
	for (int tate = 0; tate < GAME_MAP_TATE; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO; yoko++)
		{
			//キャラの当たっている場所を取得
			if (MY_CHECK_RECT_ATARI(chara, map[tate][yoko]) == TRUE)
			{
				*atariY = tate;	//atariYのアドレスが指す先の場所に、当たったモノの縦の位置を入れる
				*atariX = yoko;	//atariXのアドレスが指す先の場所に、当たったモノの縦の位置を入れる

				return TRUE;
			}
		}
	}
	return FALSE;	//当たってない
}

//######### 領域の当たり判定をする関数 #########
BOOL MY_CHECK_RECT_ATARI(RECT a, RECT b)
{
	if (a.left<b.right&&
		a.top<b.bottom&&
		a.right>b.left&&
		a.bottom>b.top
		)
	{
		return TRUE;	//当たっている
	}

	return FALSE;	//当たっていない
}

//########## プレイヤーの当たり判定の領域を設定する関数 ###########
VOID MY_SET_PLAYER_ATARI(CHARADATA *charadata)
{
	//当たり判定の領域を設定
	charadata->atariRect.left = charadata->X + charadata->atariX + 2;								//現在のX位置＋当たり判定のXの位置
	charadata->atariRect.top = charadata->Y + charadata->atariY + 2;								//現在のY位置＋当たり判定のYの位置
	charadata->atariRect.right = charadata->X + charadata->atariX + charadata->atariWidth - 2;		//現在のX位置＋当たり判定のXの位置＋当たり判定の幅
	charadata->atariRect.bottom = charadata->Y + charadata->atariY + charadata->atariHeight - 2;	//現在のY位置＋当たり判定のYの位置＋当たり判定の高さ

	return;
}

//########## プレイヤーを操作する関数 ###########
VOID MY_PLAY_PLAYER_OPERATION(VOID)
{
	int retAtariX = 0;  //当たっているマップの場所
	int retAtariY = 0;

	BOOL IsKeyDown = MY_PLAY_PLAYER_OPERATION_KEY(&retAtariX, &retAtariY);	//キーを押しているか判断

	return;
}

//########### プレイヤーをキー操作する関数 #########

BOOL MY_PLAY_PLAYER_OPERATION_KEY(int *x, int *y)
{
	BOOL IsKeyDown = FALSE;	//キーが押されたか

	if (AllKeyState[KEY_INPUT_LEFT] != 0)	//左矢印キーがおされていたとき
	{
		IsKeyDown = TRUE;	//キーを押された

		Myplayer.CanMoveLeft = TRUE;	//左方向に、まだ動ける

		MY_SET_PLAYER_ATARI(&Myplayer);	//プレイヤーの当たり判定領域を設定
		Myplayer.atariRect.left -= 4;	//少し当たり判定の領域を左にずらす
		Myplayer.atariRect.right -= 4;	//少し当たり判定の領域を左にずらす

		if (MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(Myplayer.atariRect,MapImage_W.rect_NG, x, y) == TRUE)
		{
			Myplayer.CanMoveLeft = FALSE;	//	左に行けない
		}

		if (Myplayer.CanMoveLeft == TRUE)	//左に移動できるとき
		{
			if (Myplayer.ScrollOK_X == FALSE)	//スクロールできないとき
			{
				if (Myplayer.X > 0)
				{
					Myplayer.X -= Myplayer.Speed;	//プレイヤーを左に移動
				}
			}
			else   //スクロールできるとき
			{
				if (ScrollCntYoko > 0)  //マップ外へスクロールしない
				{
					ScrollCntYoko -= Myplayer.Speed;	//画面を左にスクロール	
				}
			}

			if (Myplayer.MoveDistX > 0)
			{
				Myplayer.MoveDistX -= Myplayer.Speed;
			}

		}
	}
	if (AllKeyState[KEY_INPUT_RIGHT] != 0)	//右矢印キーが押されていたら
	{
		IsKeyDown = TRUE;

		Myplayer.CanMoveRight = TRUE;

		MY_SET_PLAYER_ATARI(&Myplayer);	//プレイヤーの当たり判定の領域を設定
		Myplayer.atariRect.left += 4;	//少し、プレイヤーの当たり判定の領域を右にずらす
		Myplayer.atariRect.right += 4;	//少し、プレイヤーの当たり判定の領域を右にずらす

		if (MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(Myplayer.atariRect, MapImage_W.rect_NG, x, y) == TRUE)	//右に行けないものと当たったとき
		{
			Myplayer.CanMoveRight = FALSE;	//右に行けない
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

			if (AllKeyState[KEY_INPUT_UP] != 0)		//上矢印キーが押されているとき
			{
				IsKeyDown = TRUE;

				Myplayer.CanMoveUp = TRUE;	//上方向にまだ動ける

				MY_SET_PLAYER_ATARI(&Myplayer);
				Myplayer.atariRect.top -= 4;
				Myplayer.atariRect.bottom -= 4;

				if (MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(Myplayer.atariRect, MapImage_W.rect_NG, x, y) == TRUE)
				{
					Myplayer.CanMoveUp = FALSE;	//上に行けない
				}

				if (Myplayer.CanMoveUp == TRUE)		//上に移動できるとき
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
			

			if (AllKeyState[KEY_INPUT_DOWN] != 0)	//下矢印キーが押されていた時
			{
				IsKeyDown = TRUE;

				Myplayer.CanMoveDown = TRUE;

				Myplayer.CanMoveDown = TRUE;	//上方向にまだ動ける

				MY_SET_PLAYER_ATARI(&Myplayer);
				Myplayer.atariRect.top += 4;
				Myplayer.atariRect.bottom += 4;

				if (MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(Myplayer.atariRect, MapImage_W.rect_NG, x, y) == TRUE)
				{
					Myplayer.CanMoveDown = FALSE;	//上に行けない
				}

				if (Myplayer.CanMoveDown == TRUE)	//下に移動できるとき
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

			//マップの左側にいるときは、プレイヤーを動かす
			if (Myplayer.MoveDistX > 0 &&
				Myplayer.MoveDistX <= GAME_MAP_YOKO_SIZE * 10)	//プレイヤーの動いた距離が一定以上であれば
			{
				Myplayer.ScrollOK_X = FALSE;					//マップを止めて、プレイヤーを動かす
			}

			//マップの真ん中あたりにいるときは、マップを動かす
			if (Myplayer.MoveDistX > GAME_MAP_YOKO_SIZE * 10 &&
				Myplayer.MoveDistX <= GAME_MAP_YOKO_SIZE * (GAME_MAP_YOKO - 15))
			{
				Myplayer.ScrollOK_X = TRUE;					//マップを動かす
			}

			//マップの右側にいるときは、プレイヤーを動かす
			if (Myplayer.MoveDistX > GAME_MAP_YOKO_SIZE*(GAME_MAP_YOKO - 15) &&
				Myplayer.MoveDistX <= GAME_MAP_YOKO_SIZE * GAME_MAP_YOKO)
			{
				Myplayer.ScrollOK_X = FALSE;				//マップを止めて、プレイヤーを動かす
			}

			//マップの上側にいるときは、プレイヤーを動かす
			if (Myplayer.MoveDistY > 0 &&
				Myplayer.MoveDistY <= GAME_MAP_TATE_SIZE * 10)
			{
				Myplayer.ScrollOK_Y = FALSE;				//マップを止めて、プレイヤーを動かす
			}

			//マップの真ん中あたりにいるときは、マップを動かす
			if (Myplayer.MoveDistY > GAME_MAP_TATE_SIZE * 10 &&
				Myplayer.MoveDistY <= GAME_MAP_TATE_SIZE * (GAME_MAP_TATE - 9))	//プレイヤーの動いた距離が一定以上であれば(開始地点)
			{
				Myplayer.ScrollOK_Y = TRUE;				//マップを動かす
			}

			//マップの下側にいるときは、プレイヤーを動かす
			if (Myplayer.MoveDistY > GAME_MAP_TATE_SIZE*(GAME_MAP_TATE - 9) &&	//プレイヤーの動いた距離が一定以上であれば(終了地点)
				Myplayer.MoveDistY <= GAME_MAP_TATE_SIZE * GAME_MAP_TATE)
			{
				Myplayer.ScrollOK_Y = FALSE;	//マップを止めて、プレイヤーを動かす
			}

	return IsKeyDown;
}

//########## 画像を読み込む設定をする関数 ##########
//引　数：画像構造体　：設定する画像構造体の変数
//引　数：int　：画像の横の位置
//引　数：int　：画像の縦の位置
//引　数：const char *：読み込む画像のファイルパス
//戻り値：BOOL：エラー時：FALSE
BOOL MY_GAZOU_LOAD(GAZOU *g, int x, int y, const char *path)
{
	wsprintf(g->FilePath, path);						//ファイルパスをコピー
	g->Handle = LoadGraph(g->FilePath);					//画像をメモリに読み込み、ハンドルを取得

	if (g->Handle == -1) { return FALSE; }				//画像読み込みエラー

	GetGraphSize(g->Handle, &g->Width, &g->Height);		//画像サイズを取得
	g->X = x;
	g->Y = y;
	g->C_Width = g->Width / 2;							//画像の横サイズの中心を取得
	g->C_Height = g->Height / 2;						//画像の縦サイズの中心を取得

	return TRUE;
}

//########## MAPを分割して読み込む設定をする関数 ##########
//引　数：MAP構造体　：設定する画像構造体(分割)の変数
//引　数：int　：画像の分割数
//引　数：int　：画像の横の分割数
//引　数：int　：画像の縦の分割数
//引　数：int　：画像の横の分割サイズ
//引　数：int　：画像の縦の分割サイズ
//引　数：const char *：読み込む画像のファイルパス
//戻り値：BOOL：エラー時：FALSE
BOOL MY_MAP_LOAD_BUNKATSU(MAP *m, int bun_num, int bun_x_num, int bun_y_num, int bun_width, int bun_height, const char *path)
{
	int ret = 0;
														//画像をメモリに分割して読み込み、ハンドルを取得
	ret = LoadDivGraph(path, bun_num, bun_x_num, bun_y_num, bun_width, bun_height, m->Handle);

	if (ret == -1) { return FALSE; }	//画像読み込みエラー

	for (int cnt = 0; cnt < GAME_MAP_1_YOKO_MAX * GAME_MAP_1_TATE_MAX; cnt++)
	{
		//画像サイズを取得
		GetGraphSize(
			m->Handle[cnt],		//ハンドルから、画像の幅と高さを取得
			&m->Width[cnt],		//MAP構造体の幅　に、画像の幅　を設定する
			&m->Height[cnt]);	//MAP構造体の逆さに、画像の高さを設定する			

		m->C_Width[cnt] = m->Width[cnt] / 2;			//画像の横サイズの中心を取得
		m->C_Height[cnt] = m->Height[cnt] / 2;			//画像の縦サイズの中心を取得
	}

	return TRUE;
}


//########## MAPを分割して読み込む設定をする関数 ##########
//引　数：MAP構造体　：設定する画像構造体(分割)の変数
//引　数：int　：画像の分割数
//引　数：int　：画像の横の分割数
//引　数：int　：画像の縦の分割数
//引　数：int　：画像の横の分割サイズ
//引　数：int　：画像の縦の分割サイズ
//引　数：const char *：読み込む画像のファイルパス
//戻り値：BOOL：エラー時：FALSE
BOOL MY_MAP_2_LOAD_BUNKATSU(MAP *m, int bun_num, int bun_x_num, int bun_y_num, int bun_width, int bun_height, const char *path)
{
	int ret = 0;
	wsprintf(m->FilePath, path);						//ファイルパスをコピー

														//画像をメモリに分割して読み込み、ハンドルを取得
	ret = LoadDivGraph(m->FilePath, bun_num, bun_x_num, bun_y_num, bun_width, bun_height, m->Handle);

	if (ret == -1) { return FALSE; }	//画像読み込みエラー

	for (int cnt = 0; cnt < GAME_MAP_2_YOKO_MAX * GAME_MAP_2_TATE_MAX; cnt++)
	{
		//画像サイズを取得
		GetGraphSize(
			m->Handle[cnt],		//ハンドルから、画像の幅と高さを取得
			&m->Width[cnt],		//MAP構造体の幅　に、画像の幅　を設定する
			&m->Height[cnt]);	//MAP構造体の逆さに、画像の高さを設定する			

		m->C_Width[cnt] = m->Width[cnt] / 2;			//画像の横サイズの中心を取得
		m->C_Height[cnt] = m->Height[cnt] / 2;			//画像の縦サイズの中心を取得
	}

	return TRUE;
}

//########## MAPを分割して読み込む設定をする関数 ##########
//引　数：MAP構造体　：設定する画像構造体(分割)の変数
//引　数：int　：画像の分割数
//引　数：int　：画像の横の分割数
//引　数：int　：画像の縦の分割数
//引　数：int　：画像の横の分割サイズ
//引　数：int　：画像の縦の分割サイズ
//引　数：const char *：読み込む画像のファイルパス
//戻り値：BOOL：エラー時：FALSE
BOOL MY_MAP_3_LOAD_BUNKATSU(MAP *m, int bun_num, int bun_x_num, int bun_y_num, int bun_width, int bun_height, const char *path)
{
	int ret = 0;
	wsprintf(m->FilePath, path);						//ファイルパスをコピー

														//画像をメモリに分割して読み込み、ハンドルを取得
	ret = LoadDivGraph(m->FilePath, bun_num, bun_x_num, bun_y_num, bun_width, bun_height, m->Handle);

	if (ret == -1) { return FALSE; }	//画像読み込みエラー

	for (int cnt = 0; cnt < GAME_MAP_3_YOKO_MAX * GAME_MAP_3_TATE_MAX; cnt++)
	{
		//画像サイズを取得
		GetGraphSize(
			m->Handle[cnt],		//ハンドルから、画像の幅と高さを取得
			&m->Width[cnt],		//MAP構造体の幅　に、画像の幅　を設定する
			&m->Height[cnt]);	//MAP構造体の逆さに、画像の高さを設定する			

		m->C_Width[cnt] = m->Width[cnt] / 2;			//画像の横サイズの中心を取得
		m->C_Height[cnt] = m->Height[cnt] / 2;			//画像の縦サイズの中心を取得
	}

	return TRUE;
}

//########## MAPを分割して読み込む設定をする関数 ##########
//引　数：MAP構造体　：設定する画像構造体(分割)の変数
//引　数：int　：画像の分割数
//引　数：int　：画像の横の分割数
//引　数：int　：画像の縦の分割数
//引　数：int　：画像の横の分割サイズ
//引　数：int　：画像の縦の分割サイズ
//引　数：const char *：読み込む画像のファイルパス
//戻り値：BOOL：エラー時：FALSE
BOOL MY_MAP_4_LOAD_BUNKATSU(MAP *m, int bun_num, int bun_x_num, int bun_y_num, int bun_width, int bun_height, const char *path)
{
	int ret = 0;
	wsprintf(m->FilePath, path);						//ファイルパスをコピー

														//画像をメモリに分割して読み込み、ハンドルを取得
	ret = LoadDivGraph(m->FilePath, bun_num, bun_x_num, bun_y_num, bun_width, bun_height, m->Handle);

	if (ret == -1) { return FALSE; }	//画像読み込みエラー

	for (int cnt = 0; cnt < GAME_MAP_4_YOKO_MAX * GAME_MAP_4_TATE_MAX; cnt++)
	{
		//画像サイズを取得
		GetGraphSize(
			m->Handle[cnt],		//ハンドルから、画像の幅と高さを取得
			&m->Width[cnt],		//MAP構造体の幅　に、画像の幅　を設定する
			&m->Height[cnt]);	//MAP構造体の逆さに、画像の高さを設定する			

		m->C_Width[cnt] = m->Width[cnt] / 2;			//画像の横サイズの中心を取得
		m->C_Height[cnt] = m->Height[cnt] / 2;			//画像の縦サイズの中心を取得
	}

	return TRUE;
}

//########## CHARAを分割して読み込む設定をする関数 ##########
//引　数：CHARAIMAGE構造体　：設定するCHARAIMAGE構造体(分割)の変数
//引　数：int　：画像の分割数
//引　数：int　：画像の横の分割数
//引　数：int　：画像の縦の分割数
//引　数：int　：画像の横の分割サイズ
//引　数：int　：画像の縦の分割サイズ
//引　数：const char *：読み込む画像のファイルパス
//戻り値：BOOL：エラー時：FALSE
BOOL MY_CHARA_LOAD_BUNKATSU(CHARAIMAGE *c, int bun_num, int bun_x_num, int bun_y_num, int bun_width, int bun_height, const char *path)
{
	int retLoad;

	wsprintf(c->FilePath, path);  //ファイルのパスをコピー

	
	retLoad = LoadDivGraph(c->FilePath, bun_num, bun_x_num, bun_y_num, bun_width, bun_height, c->Handle);	//画像をメモリに分割して読み込み、ハンドルを取得

	if (retLoad == -1) { return FALSE; }	//画像読み込みエラー

	for (int cnt = 0; cnt < GAME_MAP_BUN_YOKO_CNT_MAX*GAME_MAP_BUN_TATE_CNT_MAX; cnt++)
	{
		//画像サイズを取得
		GetGraphSize(
			c->Handle[cnt],		//ハンドルから、画像の幅と高さを取得し
			&c->Width[cnt],		//MAP構造体の幅に、画像の幅を設定する
			&c->Height[cnt]);	//MAP構造体の高さに、画僧の高さを設定する

		c->C_Width[cnt] = c->Width[cnt] / 2;	//画像の横サイズの中心位置を取得
		c->C_Height[cnt] = c->Width[cnt] / 2;	//画像の縦サイズの中心位置を取得
	}

	return TRUE;
}

//########## マップの(上)判定の種類の設定をする ########
BOOL MY_MAP_READ_CSV_UE_KIND_SET(MAP *mapdata)
{
	int Soeji;

	//通行できるマップ
	Soeji = 0;
	mapdata->mapOKKind[Soeji++] = 149;	//階段
	mapdata->mapOKKind[Soeji++] = 150;	//階段
	mapdata->mapOKKind[Soeji++] = 151;	//階段
	mapdata->mapOKKind[Soeji++] = 165;	//階段
	mapdata->mapOKKind[Soeji++] = 166;	//階段
	mapdata->mapOKKind[Soeji++] = 167;	//階段
	mapdata->mapOKKind[Soeji++] = 181;	//階段
	mapdata->mapOKKind[Soeji++] = 182;	//階段
	mapdata->mapOKKind[Soeji++] = 183;	//階段
	//通行できる種類の残りを-1で埋める
	Soeji = 0;
	for (int cnt = Soeji; cnt < GAME_MAP_OK_KIND; cnt++)
	{
		mapdata->mapOKKind[cnt] = -1;
	}

	//通行できない種類の残りを-1で埋める
	Soeji = 0;
	for (int cnt = Soeji; cnt < GAME_MAP_NG_KIND; cnt++)
	{
		mapdata->mapNGKind[cnt] = -1;
	}

	return TRUE;
}

//########## マップ(中)判定の種類を設定する ###########
BOOL MY_MAP_READ_CSV_NAKA_KIND_SET(MAP *mapdata)
{
	int Soeji;

	//通行できる種類の残りを-1で埋める
	Soeji = 0;
	for (int cnt = Soeji; cnt < GAME_MAP_OK_KIND; cnt++)
	{
		mapdata->mapOKKind[cnt] = -1;
	}


	//通行できないマップ
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

	//通行できない種類の残りを-1で埋める
	for (int cnt = Soeji; cnt < GAME_MAP_NG_KIND; cnt++)
	{
		mapdata->mapNGKind[cnt] = -1;
	}

	return TRUE;
}

//########## マップ(下)判定の種類を設定する ########
BOOL MY_MAP_READ_CSV_SITA_KIND_SET(MAP *mapdata)

{
	int Soeji;

	//通行できるマップ
	Soeji = 0;
	mapdata->mapOKKind[Soeji++] = 0;

	//通行できる種類の残りを-1で埋める
	Soeji = 0;
	for (int cnt = Soeji; cnt < GAME_MAP_OK_KIND; cnt++)
	{
		mapdata->mapOKKind[cnt] = -1;
	}

	//通行できない種類の残りを-1で埋める
	Soeji = 0;
	for (int cnt = Soeji; cnt < GAME_MAP_NG_KIND; cnt++)
	{
		mapdata->mapNGKind[cnt] = -1;
	}

	return TRUE;
}


//########## ゲームマップのCSVを読み込む関数 ##########
BOOL MY_MAP_READ_CSV_NUM(MAP *mapdata, const char *path,const char *mapname)
{

	FILE  *fp;

	if ((fp = fopen(path, "r")) == NULL)	//ファイルを読み込みモード(r)で開く
	{
		return FALSE;
	}//異常終了	

	 //ここから正常に読み込めたときの処理****************************************

	int result = 0;			//ファイルの最後かチェック
	int LoopCnt = 0;		//ループカウンタ
							
	//ファイルから数値を一つ読み込み(%d,)、配列に格納する
	while (fscanf(fp, "%d,", &mapdata->data[LoopCnt / GAME_MAP_YOKO][LoopCnt % GAME_MAP_YOKO]) != EOF)	//End Of File（ファイルの最後）ではないとき繰り返す
	{
		mapdata->mapdate_Init[LoopCnt / GAME_MAP_YOKO][LoopCnt%GAME_MAP_YOKO]
			= mapdata->data[LoopCnt / GAME_MAP_YOKO][LoopCnt%GAME_MAP_YOKO];  //値をコピー

		LoopCnt++;
	}
	fclose(fp);	//ファイルを閉じる

	wsprintf(mapdata->name, mapname); //マップの名称をコピー

	
	

	return TRUE;
}





//########## マップを表示する関数 ##########
VOID MY_PLAY_MAP_DRAW(MAP MapImage)
{
	//スクロールするマップを描画
	for (int tate = 0; tate < GAME_MAP_TATE; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO; yoko++)
		{
			if ((yoko + 1) * GAME_MAP_YOKO_SIZE - ScrollCntYoko >= 0 &&
				(yoko + 0) * GAME_MAP_YOKO_SIZE - ScrollCntYoko <= GAME_WIDTH &&	//画面に写っているならばならば
				(tate + 1) * GAME_MAP_TATE_SIZE - ScrollCntTate >= 0 &&
				(tate + 0) * GAME_MAP_TATE_SIZE - ScrollCntTate <= GAME_HEIGHT
				) //画面に写っているならば
			{
				DrawGraph(
					yoko * GAME_MAP_YOKO_SIZE - ScrollCntYoko,			//位置からスクロール量を引く
					tate * GAME_MAP_TATE_SIZE - ScrollCntTate,
					MapImage.Handle[MapImage.data[tate][yoko]], TRUE);	//マップをスクロールしながら描画


			}
		}
	}
}



//######### プレイヤーを表示する関数 ###########
VOID MY_PLAY_PLAYER_DRAW(CHARADATA player)
{
	//プレイヤーを描画	
	DrawGraph(
		player.X,
		player.Y,
		player.Handle[player.NowHandleNum], TRUE);


	if (AllKeyState[KEY_INPUT_LEFT] != 0)    //左矢印キーが押されていた時
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
				Myplayer.NowHandleNum++;	//次の左向きの画像
			}
			else
			{
				Myplayer.NowHandleNum = 9; //一番最初の左向きの画像
			}
		}
	}

	else if (AllKeyState[KEY_INPUT_RIGHT] != 0)  //右矢印キーが押されているとき
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
				Myplayer.NowHandleNum++;	//次の右向きの画像
			}
			else
			{
				Myplayer.NowHandleNum = 3; //一番最初の右向きの画像
			}
		}
	}

	else if (AllKeyState[KEY_INPUT_UP] != 0)	//上矢印キーが押されているとき
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
				Myplayer.NowHandleNum++;	//次の上向きの画像
			}
			else
			{
				Myplayer.NowHandleNum = 0; //一番最初の上向きの画像
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
				Myplayer.NowHandleNum++;	//次の左向きの画像
			}
			else
			{
				Myplayer.NowHandleNum = 6; //一番最初の左向きの画像
			}
		}
	}
	return;
}


//######### ウィンドウプロシージャ関数 ############
LRESULT CALLBACK MY_WNDPROC(HWND hwnd, UINT mgs, WPARAM wp, LPARAM lp)
{
	switch (mgs)
	{

	case WM_CREATE:	//ウィンドウの生成＆初期化

		IsWM_CREATE = TRUE;	//WM_CREATE正常終了

		return 0;

	case WM_CLOSE:	//閉じるボタンを押したとき

		MessageBox(hwnd, TEXT("ゲームを終了します。"), TEXT("終了メッセージ"), MB_OK);
		break;

	case WM_RBUTTONDOWN:	//マウスの右ボタンを押したとき

		SendMessage(hwnd, WM_CLOSE, 0, 0);	//WM_CLOSEメッセージキューに追加
		break;

	case WM_LBUTTONDOWN:

		PostMessage(hwnd, WM_NCLBUTTONDOWN, (WPARAM)HTCAPTION, lp);		//WM_NCLBUTTONDOWN(タイトルバーでマウスの左ボタンを押した)
		break;

	case WM_ACTIVATE:

		if (IsActiveCheck == TRUE)	//画面のアクティブチェックの有効化
		{
			switch (wp)
			{
			case WA_INACTIVE:	//非アクティブ化

				StopActiveStartTime = GetNowCount();

				break;

			case WA_ACTIVE:	//キーボードなどでアクティブ化

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

	case WM_DESTROY:	//ウィンドウが破棄されたとき

		PostQuitMessage(0);	//メッセージキューに WM_QUIT を送る
		return 0;
	}

	//デフォルトのウィンドウプロシージャ関数を呼び出す
	return DefWindowProc(hwnd, mgs, wp, lp);
}