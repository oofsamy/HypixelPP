#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cpr/cpr.h>
#include "nlohmann.hpp"
#include <fmt/core.h>

namespace Hypixel {
	struct Friend {
		std::string FriendID;
		std::string UUIDSender;
		std::string UUIDReciever;
		uint64_t Started;

		std::string ToString() {
			return fmt::format("Friend ID: {}\nUUID Sender: {}\nUUID Reciever: {}\nStarted: {}\n");
		}
	};
	
	struct Game {
		uint64_t Date;
		std::string GameType;
		std::string Mode;
		std::string Map;
		uint64_t Ended;

		std::string ToString() {
			return fmt::format("Date: {}\nGame Type: {}\nMode: {}\nMap: {}\nEnded: {}\n");
		}
	};

	struct Session {
		bool Online;
		std::string GameType;
		std::string Mode;
		std::string Map;

		std::string ToString() {
			return fmt::format("Online: {}\nGame Type: {}\nMode: {}\nMap: {}\n");
		}
	};

	struct GuildMember {
		std::string UUID;
		std::string GuildRank;
		uint64_t Joined;
		uint16_t QuestParticipation;
		uint32_t ExpHistory[7];
	};

	struct GuildRank {
		std::string Name;
		bool Default;
		uint8_t Priority;
		uint64_t Created;

		std::string ToString() {
			return fmt::format("Name: {}\nDefault: {}\nPriority\nCreated: {}\n");
		}
	};

	struct GuildAchievements {
		uint32_t Winners;
		uint32_t ExperienceKings;
		uint32_t OnlinePlayers;

		std::string ToString() {
			return fmt::format("Winners: {}\nExperience Kings: {}\nOnline Players: {}\n");
		}
	};

	struct GuildExpByGameType {
		uint32_t Prototype;
		uint32_t Pit;
		uint32_t TntGames;
		uint32_t WoolGames;
		uint32_t SuperSmash;
		uint32_t MCGO;
		uint32_t SkyWars;
		uint32_t Arcade;
		uint32_t Replay;
		uint32_t Duels;
		uint32_t SMP;
		uint32_t Walls3;
		uint32_t UHC;
		uint32_t Walls;
		uint32_t Arena;
		uint32_t SurvivalGames;
		uint32_t Paintball;
		uint32_t Legacy;
		uint32_t Quakecraft;
		uint32_t Gingerbread;
		uint32_t Battleground;
		uint32_t Housing;
		uint32_t Skyblock;
		uint32_t BuildBattle;
		uint32_t Vampirez;
		uint32_t Bedwars;
		uint32_t MurderMystery;
		uint32_t SpeedUHC;
	};

	struct AuctionBid {
		std::string AuctionID;
		std::string BidderUUID;
		std::string ProfileID;
		uint32_t Amount;
		uint64_t Timestamp;
		
		std::string ToString() {
			return fmt::format("Auction ID: {}\nBidder UUID: {}\nProfile ID: {}\nAmount: {}\nTimestamp: {}\n");
		}
	};

	struct Auction {
		std::string UUID;
		std::string AuctionerUUID;
		std::string ProfileID;
		std::vector<std::string> Coop;
		uint64_t Start;
		uint64_t End;
		std::string ItemName;
		std::string ItemLore;
		//UNKNOWN STRING: EXTRA "Enchanted Book Enchanted Book Rejuvenate"
		std::string Category;
		std::string Tier;
		uint32_t StartingBid;
		//STRING BYTES, NEED NBT PARSER
		bool Claimed;
		std::vector<std::string> ClaimedBidders;
		uint32_t HighestBidAmount;
		uint64_t LastUpdated;
		bool Bin;
		std::vector<AuctionBid> Bids;
		std::string ItemUUID;

		std::string ToString() { return fmt::format("UUID: {}\nAuctioneer: {}\nProfile ID: {}\n"); }
	};

	struct BazaarSummary {
		uint32_t Amount;
		uint32_t PricePerUnit;
		uint32_t Orders;

		std::string ToString() { return fmt::format("Amount: {}\nPrice Per Unit: {}\nOrders: {}\n", Amount, PricePerUnit, Orders); }
	};

	struct BazaarQuickStatus {
		std::string ProductID;
		uint32_t SellPrice;
		uint32_t SellVolume;
		uint32_t SellMovingWeek;
		uint32_t SellOrders;
		uint32_t BuyPrice;
		uint32_t BuyVolume;
		uint32_t BuyMovingWeek;
		uint32_t BuyOrders;

		std::string ToString() {
			return fmt::format("Product ID: {}\nSell Price: {}\nSell Volume: {}\nSell Moving Week: {}\nSell Orders: {}\nBuy Price: {}\nBuy Volume:{}Buy Moving Week: {}\nBuy Orders: {}", 
								ProductID, SellPrice, SellVolume, SellMovingWeek, SellOrders, BuyPrice, BuyVolume, BuyMovingWeek, BuyOrders);
		}
	};

	struct Product {
		std::string ProductID;
		std::vector<BazaarSummary> SellSummary;
		std::vector<BazaarSummary> BuySummary;

		BazaarQuickStatus QuickStatus;
	};

	struct _PlayerStat { std::string Name; };

	struct UHCStats : _PlayerStat {
		uint32_t Coins;
		bool ClearupAchievement;
		bool SavedStats;
		std::string EquippedKit;
		uint32_t Deaths;
		uint32_t KitWorkingTools;
	};

	struct TNTGamesStats : _PlayerStat {
		std::vector<std::string> Packages;
		
		uint32_t Coins;
		uint32_t Wins;
		uint32_t NewBloodWizardRegen;
		uint32_t NewSpleefTripleshot;
		uint32_t NewFireWizardExplode;
		uint32_t NewSpleefDoubleJumps;
		uint32_t NewIceWizardRegen;
		uint32_t NewSpleefRepulsor;
		uint32_t NewWitherWizardExplode;
		uint32_t NewWitherWizardRegen;
		uint32_t NewFireWizardRegen;
		uint32_t NewTNTTagSpeedy;
		uint32_t NewKineticWizardRegen;
		uint32_t NewPvpRunDoubleJumps;
		uint32_t NewBloodWizardExplode;
		uint32_t NewKineticWizardRegen;
		uint32_t NewTNTRunDoubleJumps;
		uint32_t NewIceWizardExplode;
		uint32_t RunPotionsSplashedOnPlayers;
		uint32_t RecordTNTRun;
		uint32_t DeathsTNTRun;
		uint32_t Winstreak;
		uint32_t KillsTNTTag;
		uint32_t DeathsBowspleef;
		uint32_t TagSpeedItUp;
		uint64_t LastTourneyAd;
	};

	struct BaseResult {
		uint8_t StatusCode;
		std::string Cause;

		std::string ToStringBase() { if (StatusCode < 200 || StatusCode > 299) { return fmt::format("Status Code: {}\nCause: {}"); } else { return fmt::format("Status Code: {}", StatusCode); } }
	};

	struct KeyInfoResult : BaseResult {
		std::string Key;
		std::string Owner;
		uint16_t Limit;
		uint16_t QueriesInPastMinute;
		uint16_t TotalQueries;

		std::string ToString() { return fmt::format("Key: {}\nOwner: {}\nLimit: {}\nQueries In Past Minute: {}\nTotal Queries: {}", Key, Owner, Limit, QueriesInPastMinute, TotalQueries); }
	};

	struct PlayerDataResult : BaseResult {
		std::string ID;
		std::string UUID;
		std::string DisplayName;
		uint64_t FirstLogin;
		std::vector<std::string> KnownAliases;
		std::vector<std::string> KnownAliasesLower;
		uint64_t LastLogin;
		std::string PlayerName; //I don't know why there is another field for this, maybe it's useful in some way, idk
		std::vector<std::string> AchievementsOneTime;
		uint32_t Karma;
		std::vector<_PlayerStat> Stats;
		uint64_t LastLogout;
	};

	struct FriendsResult : BaseResult {
		std::string UUID;
		std::vector<Friend> Friends;
	};

	struct RecentGamesResult : BaseResult {
		std::string UUID;
		std::vector<Game> Games;

		std::string ToString() {
			std::string Temp;
			for (Hypixel::Game& G : Games) {
				Temp = Temp + (fmt::format("\n\nDate: {}\nGame Type: {}\nMode: {}\nMap: {}\nEnded: {}", G.Date, G.GameType, G.Mode, G.Map, G.Ended));
			}

			return fmt::format("UUID: {}{}", UUID, Temp);
		}
	};


	struct OnlineStatusResult : BaseResult {
		std::string UUID;
		Session Session;
	};

	struct GuildInformationResult : BaseResult {
		std::string GuildID;
		std::string Name;
		std::string NameLowered;
		uint32_t Coins;
		uint32_t CoinsEver;
		uint64_t Created;
		std::vector<GuildMember> Members;
		std::vector<GuildRank> Ranks;
		GuildAchievements Achievements;
		uint32_t Experience;
		std::vector<std::string> PreferredGames;
		bool PubliclyListed;
		std::string Tag;
		std::string TagColor;
		uint32_t ChatMute;
		GuildExpByGameType ExpByGameType;
	};

	struct RankedSkywarsDataResult : BaseResult {
		std::string Key;
		uint32_t Position;
		uint32_t Score;
	};

	struct AuctionsDataResult : BaseResult {
		uint32_t Page;
		uint32_t TotalPages;
		uint32_t TotalAuctions;
		uint64_t LastUpdated;
		std::vector<Auction> Auctions;

		std::string ToString() { return fmt::format("Page: {}\nTotalPages: {}\nTotalAuctions: {}\nLastUpdated: {}", Page, TotalPages, TotalAuctions, LastUpdated); }
	};

	struct BazaarDataResult : BaseResult {
		uint64_t LastUpdated;
		std::vector<Product> Products;

		std::string ToString() { 
			std::string Temp;

			for (Hypixel::Product Pr : Products) {
				Temp = Temp + fmt::format("Product ID: {}\nBuy Summaries:\n\n", Pr.ProductID);

				for (Hypixel::BazaarSummary Buy : Pr.BuySummary) { Temp = Temp + Buy.ToString() + "\n"; }

				Temp = Temp + "Sell Summaries:\n\n";

				for (Hypixel::BazaarSummary Sell : Pr.SellSummary) { Temp = Temp + Sell.ToString() + "\n"; }

				Temp = Temp + Pr.QuickStatus.ToString();
			}

			return fmt::format("LastUpdated: {}\n{}", LastUpdated, Temp);
		}
	};

}

class HypixelAPI {
private:
	std::string m_APIKEY;

	Hypixel::GuildInformationResult GetGuild(std::string Response, int StatusCode) {
		const auto Result = nlohmann::json::parse(Response);

		if (Result["success"] == false) {
			Hypixel::GuildInformationResult R{};

			R.StatusCode = StatusCode;
			R.Cause = Result["cause"];

			return R;
		} else {
			Hypixel::GuildInformationResult R{};

			R.StatusCode = StatusCode;
			R.GuildID = Result["guild"]["_id"];
			R.Name = Result["guild"]["name"];
			R.NameLowered = Result["guild"]["name_lower"];
			R.Coins = Result["guild"]["coins"];
			R.CoinsEver = Result["guild"]["coinsEver"];
			R.Created = Result["guild"]["created"];

			for (int i = 0; i < Result["guild"]["members"].size(); i++) {
				Hypixel::GuildMember M{};

				M.UUID = Result["guild"]["members"][i]["uuid"];
				M.UUID = Result["guild"]["members"][i]["rank"];
				M.UUID = Result["guild"]["members"][i]["joined"];
				M.UUID = Result["guild"]["members"][i]["questParticipation"];

				for (int j = 0; j < Result["guild"]["members"][i]["expHistory"]; j++) {
					M.ExpHistory[j] = Result["guild"]["members"][i]["expHistory"][j];
				}

				R.Members.push_back(M);
			}

			for (int i = 0; i < Result["guild"]["ranks"].size(); i++) {
				Hypixel::GuildRank Rank{};

				Rank.Name = Result["guild"]["ranks"][i]["name"];
				Rank.Name = Result["guild"]["ranks"][i]["default"];
				Rank.Name = Result["guild"]["ranks"][i]["tag"];
				Rank.Name = Result["guild"]["ranks"][i]["created"];
				Rank.Name = Result["guild"]["ranks"][i]["priority"];

				R.Ranks.push_back(Rank);
			}

			R.Achievements.Winners = Result["guild"]["achievements"]["WINNERS"];
			R.Achievements.ExperienceKings = Result["guild"]["achievements"]["EXPERIENCE_KINGS"];
			R.Achievements.OnlinePlayers = Result["guild"]["achievements"]["ONLINE_PLAYERS"];

			R.Experience = Result["guild"]["exp"];

			for (int i = 0; i < Result["guild"]["preferredGames"].size(); i++) {
				R.PreferredGames.push_back(Result["guild"]["preferredGames"][i]);
			}

			R.PubliclyListed = Result["guild"]["publiclyListed"];
			R.Tag = Result["guild"]["tag"];
			R.TagColor = Result["guild"]["tagColor"];
			R.ChatMute = Result["guild"]["chatMute"];

			R.ExpByGameType.Prototype = Result["guild"]["guildExpByGameType"]["PROTOTYPE"];
			R.ExpByGameType.Pit = Result["guild"]["guildExpByGameType"]["PIT"];
			R.ExpByGameType.TntGames = Result["guild"]["guildExpByGameType"]["TNTGAMES"];
			R.ExpByGameType.WoolGames = Result["guild"]["guildExpByGameType"]["WOOL_GAMES"];
			R.ExpByGameType.SuperSmash = Result["guild"]["guildExpByGameType"]["SUPER_SMASH"];
			R.ExpByGameType.MCGO = Result["guild"]["guildExpByGameType"]["MCGO"];
			R.ExpByGameType.SkyWars = Result["guild"]["guildExpByGameType"]["SKYWARS"];
			R.ExpByGameType.Arcade = Result["guild"]["guildExpByGameType"]["ARCADE"];
			R.ExpByGameType.Replay = Result["guild"]["guildExpByGameType"]["REPLAY"];
			R.ExpByGameType.Duels = Result["guild"]["guildExpByGameType"]["DUELS"];
			R.ExpByGameType.SMP = Result["guild"]["guildExpByGameType"]["SMP"];
			R.ExpByGameType.Walls3 = Result["guild"]["guildExpByGameType"]["WALLS3"];
			R.ExpByGameType.UHC = Result["guild"]["guildExpByGameType"]["UHC"];
			R.ExpByGameType.Walls = Result["guild"]["guildExpByGameType"]["WALLS"];
			R.ExpByGameType.Arena = Result["guild"]["guildExpByGameType"]["ARENA"];
			R.ExpByGameType.SurvivalGames = Result["guild"]["guildExpByGameType"]["SURVIVAL_GAMES"];
			R.ExpByGameType.Paintball = Result["guild"]["guildExpByGameType"]["PAINTBALL"];
			R.ExpByGameType.Legacy = Result["guild"]["guildExpByGameType"]["LEGACY"];
			R.ExpByGameType.Quakecraft = Result["guild"]["guildExpByGameType"]["QUAKECRAFT"];
			R.ExpByGameType.Gingerbread = Result["guild"]["guildExpByGameType"]["GINGERBREAD"];
			R.ExpByGameType.Battleground = Result["guild"]["guildExpByGameType"]["BATTLEGROUND"];
			R.ExpByGameType.Housing = Result["guild"]["guildExpByGameType"]["HOUSING"];
			R.ExpByGameType.Skyblock = Result["guild"]["guildExpByGameType"]["SKYBLOCK"];
			R.ExpByGameType.BuildBattle = Result["guild"]["guildExpByGameType"]["BUILD_BATTLE"];
			R.ExpByGameType.Vampirez = Result["guild"]["guildExpByGameType"]["VAMPIREZ"];
			R.ExpByGameType.Bedwars = Result["guild"]["guildExpByGameType"]["BEDWARS"];
			R.ExpByGameType.MurderMystery = Result["guild"]["guildExpByGameType"]["MURDER_MYSTERY"];
			R.ExpByGameType.SpeedUHC = Result["guild"]["guildExpByGameType"]["SPEED_UHC"];

			return R;
		}
	}
public:
	HypixelAPI(std::string APIKEY) : m_APIKEY(APIKEY) {};

	std::string GetAPIKEY() {
		return m_APIKEY;
	}
	
	Hypixel::KeyInfoResult GetKeyInformation() {
		cpr::Response r = cpr::Get(cpr::Url{ "https://api.hypixel.net/key" },
			cpr::Parameters{ { "key" , GetAPIKEY() } });

		const auto Result = nlohmann::json::parse(r.text);

		if (Result["success"] == false) {
			Hypixel::KeyInfoResult R;
			R.StatusCode = r.status_code;
			R.Cause = Result["cause"];
			return R;
		}
		else {
			Hypixel::KeyInfoResult R{};
			R.StatusCode = r.status_code;
			R.Key = Result["record"]["key"];
			R.Owner = Result["record"]["owner"];
			R.Limit = Result["record"]["limit"];
			R.QueriesInPastMinute = Result["record"]["queriesInPastMin"];
			R.TotalQueries = Result["record"]["totalQueries"];

			return R;
		}
	}

	static Hypixel::KeyInfoResult GetKeyInformation(std::string Key) {
		cpr::Response r = cpr::Get(cpr::Url{ "https://api.hypixel.net/key" },
								   cpr::Parameters{ { "key" , Key } });

		const auto Result = nlohmann::json::parse(r.text);
		
		if (Result["success"] == false) {
			Hypixel::KeyInfoResult R;
			R.StatusCode = r.status_code;
			R.Cause = Result["record"]["cause"];
			return R;
		}
		else {
			Hypixel::KeyInfoResult R{};
			R.StatusCode = r.status_code;

			R.Key = Result["record"]["key"];
			R.Owner = Result["record"]["owner"];
			R.Limit = Result["record"]["limit"];
			R.QueriesInPastMinute = Result["record"]["queriesInPastMin"];
			R.TotalQueries = Result["record"]["totalQueries"];

			return R;
		}
	};
	
	Hypixel::PlayerDataResult GetPlayerDataInformation(std::string UUID) {
		cpr::Response r = cpr::Get(cpr::Url{ "https://api.hypixel.net/player" },
								   cpr::Parameters{ { "key" , m_APIKEY } ,{"uuid", UUID} });

		const auto Result = nlohmann::json::parse(r.text);

		if (Result["success"] == false) {
			Hypixel::PlayerDataResult R;
			R.StatusCode = r.status_code;
			R.Cause = Result["cause"];
			return R;
		}
		else {
			Hypixel::PlayerDataResult R{};
			R.StatusCode = r.status_code;

			R.UUID = Result["player"]["uuid"];
			R.DisplayName = Result["player"]["displayname"];
			R.FirstLogin = Result["player"]["FirstLogin"];

			for (int i = 0; i < Result["player"]["knownAliases"].size(); i++) {
				R.KnownAliases.push_back(Result["player"]["knownAliases"][i]);
				R.KnownAliasesLower.push_back(Result["player"]["knownAliasesLower"][i]);
			}

			R.LastLogin = Result["player"]["lastLogin"];
			R.PlayerName = Result["player"]["playername"];

			for (int i = 0; i < Result["player"]["achievementsOneTime"].size(); i++) {
				R.AchievementsOneTime.push_back(Result["player"]["achievementsOneTime"][i]);
			}

			R.Karma = Result["player"]["karma"];
			R.PlayerName = Result["player"]["playername"];
			R.LastLogout = Result["player"]["lastLogout"];

			Hypixel::UHCStats UHCS{};

			UHCS.Name = "UHC";
			UHCS.Coins = Result["player"]["stats"]["UHC"]["coins"];
			UHCS.ClearupAchievement = Result["player"]["stats"]["UHC"]["clearup_achievement"];
			UHCS.SavedStats = Result["player"]["stats"]["UHC"]["saved_stats"];
			UHCS.EquippedKit = Result["player"]["stats"]["UHC"]["equippedKit"];
			UHCS.Deaths = Result["player"]["stats"]["UHC"]["deaths"];
			UHCS.KitWorkingTools = Result["player"]["stats"]["UHC"]["kit_WORKING_TOOLS"];

			R.Stats.push_back(UHCS);

			Hypixel::TNTGamesStats TNTG{};

			TNTG.Name = "TNTGames";
			TNTG.Coins = Result["player"]["stats"]["TNTGames"]["coins"];
			TNTG.Wins = Result["player"]["stats"]["TNTGames"]["wins"];
			TNTG.NewBloodWizardRegen = Result["player"]["stats"]["TNTGames"]["new_bloodwizard_regen"];
			TNTG.NewSpleefTripleshot = Result["player"]["stats"]["TNTGames"]["new_spleef_tripleshot"];
			TNTG.NewFireWizardExplode = Result["player"]["stats"]["TNTGames"]["new_firewizard_explode"];
			TNTG.NewSpleefDoubleJumps = Result["player"]["stats"]["TNTGames"]["new_spleef_double_jumps"];
			TNTG.NewIceWizardRegen = Result["player"]["stats"]["TNTGames"]["new_icewizard_regen"];
			TNTG.NewSpleefRepulsor = Result["player"]["stats"]["TNTGames"]["new_spleef_repulsor"];
			TNTG.NewWitherWizardExplode = Result["player"]["stats"]["TNTGames"]["new_witherwizard_explode"];
			TNTG.NewWitherWizardRegen = Result["player"]["stats"]["TNTGames"]["new_witherwizard_regen"];
			TNTG.NewFireWizardRegen = Result["player"]["stats"]["TNTGames"]["new_firewizard_regen"];
			TNTG.NewTNTTagSpeedy = Result["player"]["stats"]["TNTGames"]["new_tntag_speedy"];
			TNTG.NewKineticWizardRegen = Result["player"]["stats"]["TNTGames"]["new_kineticwizard_explode"];
			TNTG.NewPvpRunDoubleJumps = Result["player"]["stats"]["TNTGames"]["new_pvprun_double_jumps"];
			TNTG.NewBloodWizardExplode = Result["player"]["stats"]["TNTGames"]["new_bloodwizard_explode"];
			TNTG.NewKineticWizardRegen = Result["player"]["stats"]["TNTGames"]["new_kineticwizard_regen"];
			TNTG.NewTNTRunDoubleJumps = Result["player"]["stats"]["TNTGames"]["new_tntrun_double_jumps"];
			TNTG.NewIceWizardExplode = Result["player"]["stats"]["TNTGames"]["new_icewizard_explode"];
			TNTG.RunPotionsSplashedOnPlayers = Result["player"]["stats"]["TNTGames"]["run_potions_splashed_on_players"];
			TNTG.RecordTNTRun = Result["player"]["stats"]["TNTGames"]["record_tntrun"];
			TNTG.DeathsTNTRun = Result["player"]["stats"]["TNTGames"]["deaths_tntrun"];
			TNTG.Winstreak = Result["player"]["stats"]["TNTGames"]["winstreak"];
			TNTG.KillsTNTTag = Result["player"]["stats"]["TNTGames"]["kills_tntag"];
			TNTG.DeathsBowspleef = Result["player"]["stats"]["TNTGames"]["deaths_bowspleef"];
			TNTG.TagSpeedItUp = Result["player"]["stats"]["TNTGames"]["tag_speeditup"];
			TNTG.LastTourneyAd = Result["player"]["stats"]["TNTGames"]["lastTourneyAd"];

			for (int i = 0; i < Result["player"]["stats"]["TNTGames"]["packages"].size(); i++) {
				TNTG.Packages.push_back(Result["player"]["stats"]["TNTGames"]["packages"][i]);
			}

			R.Stats.push_back(TNTG);

			return R;
		}
	}

	Hypixel::FriendsResult GetFriendsOfUserResult(std::string UUID) {
		cpr::Response r = cpr::Get(cpr::Url{ "https://api.hypixel.net/friends" },
								   cpr::Parameters{ { "key" , m_APIKEY } ,{"uuid", UUID} });

		const auto Result = nlohmann::json::parse(r.text);

		if (Result["success"] == false) {
			Hypixel::FriendsResult R;

			R.StatusCode = r.status_code;
			R.Cause = Result["cause"];

			return R;
		} else {
			Hypixel::FriendsResult R{};

			R.StatusCode = r.status_code;
			R.UUID = Result["uuid"];

			for (int i = 0; i < Result["records"].size(); i++) {
				Hypixel::Friend F{};

				F.FriendID = Result["records"][i]["_id"];
				F.UUIDSender = Result["records"][i]["uuidSender"];
				F.UUIDReciever = Result["records"][i]["uuidReceiver"];
				F.Started = Result["records"][i]["started"];

				R.Friends.push_back(F);
			}

			return R;
		}
	}

	Hypixel::RecentGamesResult GetRecentGamesPlayed(std::string UUID) {
		cpr::Response r = cpr::Get(cpr::Url{ "https://api.hypixel.net/recentgames" },
								   cpr::Parameters{ {"key", m_APIKEY}, {"uuid", UUID} });
		
		const auto Result = nlohmann::json::parse(r.text);

		if (Result["success"] == false) {
			Hypixel::RecentGamesResult R{};

			R.StatusCode = r.status_code;
			R.Cause = Result["cause"];

			return R;
		} else {
			Hypixel::RecentGamesResult R{};

			R.StatusCode = r.status_code;
			R.UUID = Result["uuid"];
			
			for (int i = 0; i < Result["games"].size(); i++) {
				Hypixel::Game Game{};

				Game.Date = Result["games"][i]["date"];
				Game.GameType = Result["games"][i]["gameType"];
				Game.Mode = Result["games"][i]["mode"];
				Game.Map = Result["games"][i]["map"];
				Game.Ended = Result["games"][i]["ended"];

				R.Games.push_back(Game);
			}

			return R;
		}
	}

	static Hypixel::AuctionsDataResult GetAuctionData(int Page) {
		cpr::Response r = cpr::Get(cpr::Url{ "https://api.hypixel.net/skyblock/auctions" },
								   cpr::Parameters{ {"page", std::to_string(Page)}});

		const auto Result = nlohmann::json::parse(r.text);

		if (Result["success"] == false) {
			Hypixel::AuctionsDataResult R;

			R.StatusCode = r.status_code;
			R.Cause = Result["cause"];

			return R;
		} else {
			Hypixel::AuctionsDataResult R;

			R.StatusCode = r.status_code;
			R.Page = Result["page"];
			R.TotalPages = Result["totalPages"];
			R.TotalAuctions = Result["totalAuctions"];
			R.LastUpdated = Result["lastUpdated"];
			
			for (int i = 0; i < Result["auctions"].size(); i++) {
				Hypixel::Auction A{};

				auto AuctionResult = Result["auctions"][i];

				A.UUID = AuctionResult["uuid"];
				A.AuctionerUUID = AuctionResult["auctioneer"];
				A.ProfileID = AuctionResult["profile_id"];
				//A.Coop
				A.Start = AuctionResult["start"];
				A.End = AuctionResult["end"];
				A.ItemName = AuctionResult["item_name"];
				A.ItemLore = AuctionResult["item_lore"];
				A.StartingBid = AuctionResult["starting_bid"];
				A.LastUpdated = AuctionResult["last_updated"];
				A.Bin = AuctionResult["bin"];

				R.Auctions.push_back(A);
			}

			return R;
		}
	}

	static Hypixel::BazaarDataResult GetBazaarInformation() {
		cpr::Response r = cpr::Get(cpr::Url{ "https://api.hypixel.net/skyblock/bazaar" });

		const auto Result = nlohmann::json::parse(r.text);

		if (Result["success"] == false) {
			Hypixel::BazaarDataResult R{};

			R.StatusCode = r.status_code;
			R.Cause = Result["cause"];

			return R;
		} else {
			Hypixel::BazaarDataResult R{};

			R.StatusCode = r.status_code;
			R.LastUpdated = Result["lastUpdated"];

			for (auto& ProductItem : Result["products"].items()) {
				Hypixel::Product Pr{};

				const auto Product = Result["products"][ProductItem.key()];
				
				Pr.ProductID = Product["product_id"];

				for (int i = 0; i < Product["sell_summary"].size(); i++) {
					Hypixel::BazaarSummary SellSummary{};

					SellSummary.Amount = Product["sell_summary"][i]["amount"];
					SellSummary.PricePerUnit = Product["sell_summary"][i]["pricePerUnit"];
					SellSummary.Orders = Product["sell_summary"][i]["orders"];

					Pr.SellSummary.push_back(SellSummary);
				}

				for (int i = 0; i < Product["buy_summary"].size(); i++) {
					Hypixel::BazaarSummary BuySummary{};

					BuySummary.Amount = Product["buy_summary"][i]["amount"];
					BuySummary.PricePerUnit = Product["buy_summary"][i]["pricePerUnit"];
					BuySummary.Orders = Product["buy_summary"][i]["orders"];

					Pr.BuySummary.push_back(BuySummary);
				}

				Hypixel::BazaarQuickStatus QuickStatus{};

				QuickStatus.ProductID = Product["quick_status"]["productId"];
				QuickStatus.SellPrice = Product["quick_status"]["sellPrice"];
				QuickStatus.SellVolume = Product["quick_status"]["sellVolume"];
				QuickStatus.SellMovingWeek = Product["quick_status"]["sellMovingWeek"];
				QuickStatus.SellOrders = Product["quick_status"]["sellOrders"];
				QuickStatus.BuyPrice = Product["quick_status"]["buyPrice"];
				QuickStatus.BuyVolume = Product["quick_status"]["buyVolume"];
				QuickStatus.BuyMovingWeek = Product["quick_status"]["buyMovingWeek"];
				QuickStatus.BuyOrders = Product["quick_status"]["buyOrders"];

				Pr.QuickStatus = QuickStatus;

				R.Products.push_back(Pr);
			}

			return R;
		}
	}

	Hypixel::OnlineStatusResult GetOnlineStatusOfPlayer(std::string UUID) {
		cpr::Response r = cpr::Get(cpr::Url{ "https://api.hypixel.net/status" },
								   cpr::Parameters{ {"uuid", UUID } });

		const auto Result = nlohmann::json::parse(r.text);

		if (Result["success"] == false) {
			Hypixel::OnlineStatusResult R{};

			R.StatusCode = r.status_code;
			R.Cause = Result["cause"];

			return R;
		} else {
			Hypixel::OnlineStatusResult R{};

			R.StatusCode = r.status_code;
			R.UUID = Result["uuid"];

			R.Session.Online = Result["session"]["online"];
			R.Session.GameType = Result["session"]["gameType"];
			R.Session.Mode = Result["session"]["mode"];
			R.Session.Map = Result["session"]["map"];

			return R;
		}
	}

	Hypixel::GuildInformationResult GetGuildByGuildID(std::string GuildID) {
		cpr::Response r = cpr::Get(cpr::Url{ "https://api.hypixel.net/guild" },
								   cpr::Parameters{ {"id", GuildID } });

		return GetGuild(r.text, r.status_code);
	}

	Hypixel::GuildInformationResult GetGuildByPlayerID(std::string PlayerID) {
		cpr::Response r = cpr::Get(cpr::Url{ "https://api.hypixel.net/guild" },
								   cpr::Parameters{ {"player", PlayerID } });

		return GetGuild(r.text, r.status_code);
	}

	Hypixel::GuildInformationResult GetGuildByGuildName(std::string GuildName) {
		cpr::Response r = cpr::Get(cpr::Url{ "https://api.hypixel.net/guild" },
								   cpr::Parameters{ {"name", GuildName } });

		return GetGuild(r.text, r.status_code);
	}

	Hypixel::RankedSkywarsDataResult GetRankedSkywarsInformation(std::string UUID) {
		cpr::Response r = cpr::Get(cpr::Url{ "https://api.hypixel.net/player/ranked/skywars" },
								   cpr::Parameters{ {"uuid", UUID } });

		const auto Result = nlohmann::json::parse(r.text);

		if (Result["success"] == false) {
			Hypixel::RankedSkywarsDataResult R{};

			R.StatusCode = r.status_code;
			R.Cause = Result["cause"];

			return R;
		} else {
			Hypixel::RankedSkywarsDataResult R{};

			R.Key = Result["result"]["key"];
			R.Position = Result["result"]["position"];
			R.Score = Result["result"]["score"];
		
			return R;
		}
	}


};

namespace Hypixel::Utils {
	std::string UsernameToUUID(std::string Username) {
		cpr::Response r = cpr::Get("https://api.mojang.com/users/profiles/minecraft/" + Username);
		return nlohmann::json::parse(r.text)["id"];
	}

	std::string UUIDToUsername(std::string UUID) {
		cpr::Response r = cpr::Get("https://api.mojang.com/user/profiles/" + UUID + "/names");
		return nlohmann::json::parse(r.text)[0];
	}
}
