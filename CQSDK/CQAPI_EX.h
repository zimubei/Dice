#pragma once

#include "cqdefine.h"

#include <string>
#include <map>
#include <vector>

class Unpack;

namespace CQ
{
	//增加运行日志 
	int addLog(int Priorty, const char* Type, const char* Content) noexcept;

	//发送好友消息
	//Auth=106 失败返回负值,成功返回消息ID 
	int sendPrivateMsg(long long QQ, const char* msg) noexcept;
	//发送好友消息
	//Auth=106 失败返回负值,成功返回消息ID 
	int sendPrivateMsg(long long QQ, const std::string& msg) noexcept;

	//发送群消息 
	//Auth=101 失败返回负值,成功返回消息ID
	int sendGroupMsg(long long GroupID, const char* msg) noexcept;
	//发送群消息 
	//Auth=101 失败返回负值,成功返回消息ID
	int sendGroupMsg(long long GroupID, const std::string& msg) noexcept;


	//发送讨论组消息 
	//Auth=103 失败返回负值,成功返回消息ID
	int sendDiscussMsg(long long DiscussID, const char* msg) noexcept;
	//发送讨论组消息 
	//Auth=103 失败返回负值,成功返回消息ID
	int sendDiscussMsg(long long DiscussID, const std::string& msg) noexcept;

	//发送赞 Auth=110
	int sendLike(long long QQID, int times) noexcept;

	//取Cookies (慎用，此接口需要严格授权) 
	//Auth=20
	const char* getCookies(const char* Domain) noexcept;

	//取Cookies (慎用，此接口需要严格授权) 
	//Auth=20
	const char* getCookies(const std::string& Domain) noexcept;

	//接收语音 
	const char* getRecord(
		const char* file, // 收到消息中的语音文件名 (file) 
		const char* outformat // 应用所需的格式 mp3,amr,wma,m4a,spx,ogg,wav,flac
	) noexcept;
	//接收语音 
	std::string getRecord(
		const std::string& file, // 收到消息中的语音文件名 (file) 
		const std::string& outformat // 应用所需的格式 mp3,amr,wma,m4a,spx,ogg,wav,flac
	) noexcept;

	//取CsrfToken (慎用，此接口需要严格授权) 
	//Auth=20 即QQ网页用到的bkn/g_tk等
	int getCsrfToken() noexcept;

	//取应用目录 
	//返回的路径末尾带"\" 
	const char* getAppDirectory() noexcept;

	//取登录QQ 
	long long getLoginQQ() noexcept;

	//取登录昵称 
	const char* getLoginNick() noexcept;

	//置群员移除 Auth=120 
	int setGroupKick(
		long long GroupID, long long QQID,
		CQBOOL RefuseForever = false // 如果为真，则“不再接收此人加群申请”，请慎用 
	) noexcept;

	//置群员禁言 Auth=121 
	int setGroupBan(
		long long GroupID, long long QQID,
		long long Time = 60 // 禁言的时间，单位为秒。如果要解禁，这里填写0 
	) noexcept;

	//置群管理员 Auth=122 
	int setGroupAdmin(
		long long GroupID, long long QQID,
		CQBOOL isAdmin = true // 真/设置管理员 假/取消管理员 
	) noexcept;

	//置群成员专属头衔 Auth=128 需群主权限 
	int setGroupSpecialTitle(
		long long GroupID, long long QQID,
		const char* Title, // 如果要删除，这里填空 
		long long ExpireTime = -1 // 专属头衔有效期，单位为秒。如果永久有效，这里填写-1
	) noexcept;
	//置群成员专属头衔 Auth=128 需群主权限 
	int setGroupSpecialTitle(
		long long GroupID, long long QQID,
		const std::string& Title, // 如果要删除，这里填空 
		long long ExpireTime = -1 // 专属头衔有效期，单位为秒。如果永久有效，这里填写-1
	) noexcept;

	//置全群禁言 Auth=123 
	int setGroupWholeBan(
		long long GroupID,
		CQBOOL isBan = true // 真/开启 假/关闭 
	) noexcept;

	//置匿名群员禁言 Auth=124 
	int setGroupAnonymousBan(
		long long GroupID,
		const char* AnonymousToken, // 群消息事件收到的“匿名”参数 
		long long banTime = 60 // 禁言的时间，单位为秒。不支持解禁 
	) noexcept;

	//置群匿名设置 Auth=125 
	int setGroupAnonymous(long long GroupID, CQBOOL enableAnonymous = true) noexcept;

	//置群成员名片 Auth=126 
	int setGroupCard(long long GroupID, long long QQID, const char* newGroupNick) noexcept;

	//置群成员名片 Auth=126 
	int setGroupCard(long long GroupID, long long QQID, const std::string& newGroupNick) noexcept;

	//置群退出 Auth=127 慎用,此接口需要严格授权 
	int setGroupLeave(
		long long GroupID,
		CQBOOL isDismiss = false // 真/解散本群 (群主) 假/退出本群 (管理、群成员) 
	) noexcept;

	//置讨论组退出 Auth=140 
	int setDiscussLeave(
		long long DiscussID
	) noexcept;

	//置好友添加请求 Auth=150 
	int setFriendAddRequest(
		const char* RequestToken, // 请求事件收到的“反馈标识”参数 
		int ReturnType, // #请求_通过 或 #请求_拒绝 
		const char* Remarks // 添加后的好友备注 
	) noexcept;

	//置群添加请求 Auth=151 
	int setGroupAddRequest(
		const char* RequestToken, // 请求事件收到的“反馈标识”参数 
		int RequestType, // 根据请求事件的子类型区分 #请求_群添加 或 #请求_群邀请 
		int ReturnType, // #请求_通过 或 #请求_拒绝 
		const char* Reason // 操作理由，仅 #请求_群添加 且 #请求_拒绝 时可用
	) noexcept;

	//置致命错误提示,暂时不知道干什么用的
	int setFatal(const char* ErrorMsg) noexcept;


	class GroupMemberInfo;
	//取群成员信息 (支持缓存) Auth=130 
	GroupMemberInfo getGroupMemberInfo(long long GroupID, long long QQID, CQBOOL DisableCache = false) noexcept;

	class StrangerInfo;
	//取陌生人信息 (支持缓存) Auth=131 
	StrangerInfo getStrangerInfo(long long QQID, CQBOOL DisableCache = false) noexcept;

	//取群成员列表 Auth=160  
	std::vector<GroupMemberInfo> getGroupMemberList(long long GroupID) noexcept;

	//取群列表 Auth=161  
	std::map<long long, std::string> getGroupList() noexcept;

	class FriendInfo;
	//取好友列表 Auth=162  
	std::map<long long, FriendInfo> getFriendList() noexcept;

	//是否支持发送图片，返回true为支持，返回false为不支持
	bool canSendImage() noexcept;

	//是否支持发送语音，返回大于 0 为支持，等于 0 为不支持
	bool canSendRecord() noexcept;

	//接收图片，并返回图片文件绝对路径
	const char* getImage(const char* file) noexcept;

	//接收图片，并返回图片文件绝对路径
	const char* getImage(const std::string& file) noexcept;

	//撤回消息 Auth=180
	int deleteMsg(long long MsgId) noexcept;

	const char* getlasterrmsg() noexcept;
	// 群信息
	class GroupInfo final {
		void setdata(Unpack& u);
	public:
		long long llGroup{};
		std::string strGroupName{};
		int nGroupSize = 0; // 群人数
		int nMaxGroupSize = 0;//群规模
		int nFriendCnt = 0;//好友数

		explicit GroupInfo(long long group);
		GroupInfo() = default;
		[[nodiscard]] std::string tostring() const;
	};
	// 群成员信息
	class GroupMemberInfo final
	{
		void setdata(Unpack& u);
	public:
		long long Group{};
		long long QQID{};
		std::string Nick{};
		std::string GroupNick{};
		int Gender{}; // 0/男性 1/女性
		int Age{};
		std::string Region{};
		int AddGroupTime{};
		int LastMsgTime{};
		std::string LevelName{};
		int permissions{}; //1/成员 2/管理员 3/群主
		std::string Title{};
		int ExpireTime{}; // -1 代表不过期
		CQBOOL NaughtyRecord{};
		CQBOOL canEditGroupNick{};

		explicit GroupMemberInfo(Unpack& msg);
		explicit GroupMemberInfo(const char* msg); //从API解码
		explicit GroupMemberInfo(const std::vector<unsigned char>& data); //从Unpack解码
		GroupMemberInfo() = default;

		[[nodiscard]] std::string tostring() const;
	};
	// 好友信息
	class FriendInfo final
	{
	public:
		long long QQID = 0;
		std::string nick; //昵称
		std::string remark; //备注

		explicit FriendInfo(Unpack p);
		FriendInfo() = default;
		[[nodiscard]] std::string tostring() const;
	};
	// 陌生人信息
	class StrangerInfo final
	{
	public:
		long long QQID = 0;
		std::string nick = ""; //昵称
		int sex = 255; //0/男性 1/女性 255/未知
		int age = -1; //年龄

		explicit StrangerInfo(const char* msg);
		StrangerInfo() = default;

		[[nodiscard]] std::string tostring() const;
	};
}
