
#ifndef tdlpp_IdNameBinding
#define tdlpp_IdNameBinding

#include <tdlpp/core.hpp>

namespace tdlpp { namespace log {

static inline std::string __IdNameBinding(const std::int32_t& t_id) {
    switch (t_id) {
        case (td::td_api::optionValueString::ID): { return "optionValueString"; }
        case (td::td_api::optionValueInteger::ID): { return "optionValueInteger"; }
        case (td::td_api::optionValueEmpty::ID): { return "optionValueEmpty"; }
        case (td::td_api::optionValueBoolean::ID): { return "optionValueBoolean"; }
        case (td::td_api::venue::ID): { return "venue"; }
        case (td::td_api::video::ID): { return "video"; }
        case (td::td_api::videoChat::ID): { return "videoChat"; }
        case (td::td_api::videoNote::ID): { return "videoNote"; }
        case (td::td_api::voiceNote::ID): { return "voiceNote"; }
        case (td::td_api::webPage::ID): { return "webPage"; }
        case (td::td_api::webPageInstantView::ID): { return "webPageInstantView"; }
        case (td::td_api::acceptCall::ID): { return "acceptCall"; }
        case (td::td_api::acceptTermsOfService::ID): { return "acceptTermsOfService"; }
        case (td::td_api::addChatMember::ID): { return "addChatMember"; }
        case (td::td_api::addChatMembers::ID): { return "addChatMembers"; }
        case (td::td_api::addChatToList::ID): { return "addChatToList"; }
        case (td::td_api::addContact::ID): { return "addContact"; }
        case (td::td_api::addCustomServerLanguagePack::ID): { return "addCustomServerLanguagePack"; }
        case (td::td_api::addFavoriteSticker::ID): { return "addFavoriteSticker"; }
        case (td::td_api::addLocalMessage::ID): { return "addLocalMessage"; }
        case (td::td_api::addLogMessage::ID): { return "addLogMessage"; }
        case (td::td_api::addNetworkStatistics::ID): { return "addNetworkStatistics"; }
        case (td::td_api::addProxy::ID): { return "addProxy"; }
        case (td::td_api::addRecentlyFoundChat::ID): { return "addRecentlyFoundChat"; }
        case (td::td_api::addRecentSticker::ID): { return "addRecentSticker"; }
        case (td::td_api::addSavedAnimation::ID): { return "addSavedAnimation"; }
        case (td::td_api::addStickerToSet::ID): { return "addStickerToSet"; }
        case (td::td_api::answerCallbackQuery::ID): { return "answerCallbackQuery"; }
        case (td::td_api::answerCustomQuery::ID): { return "answerCustomQuery"; }
        case (td::td_api::answerInlineQuery::ID): { return "answerInlineQuery"; }
        case (td::td_api::answerPreCheckoutQuery::ID): { return "answerPreCheckoutQuery"; }
        case (td::td_api::answerShippingQuery::ID): { return "answerShippingQuery"; }
        case (td::td_api::banChatMember::ID): { return "banChatMember"; }
        case (td::td_api::blockMessageSenderFromReplies::ID): { return "blockMessageSenderFromReplies"; }
        case (td::td_api::cancelDownloadFile::ID): { return "cancelDownloadFile"; }
        case (td::td_api::cancelPasswordReset::ID): { return "cancelPasswordReset"; }
        case (td::td_api::cancelUploadFile::ID): { return "cancelUploadFile"; }
        case (td::td_api::canTransferOwnership::ID): { return "canTransferOwnership"; }
        case (td::td_api::changeImportedContacts::ID): { return "changeImportedContacts"; }
        case (td::td_api::changePhoneNumber::ID): { return "changePhoneNumber"; }
        case (td::td_api::changeStickerSet::ID): { return "changeStickerSet"; }
        case (td::td_api::checkAuthenticationBotToken::ID): { return "checkAuthenticationBotToken"; }
        case (td::td_api::checkAuthenticationCode::ID): { return "checkAuthenticationCode"; }
        case (td::td_api::checkAuthenticationPassword::ID): { return "checkAuthenticationPassword"; }
        case (td::td_api::checkAuthenticationPasswordRecoveryCode::ID): { return "checkAuthenticationPasswordRecoveryCode"; }
        case (td::td_api::checkChangePhoneNumberCode::ID): { return "checkChangePhoneNumberCode"; }
        case (td::td_api::checkChatInviteLink::ID): { return "checkChatInviteLink"; }
        case (td::td_api::checkChatUsername::ID): { return "checkChatUsername"; }
        case (td::td_api::checkCreatedPublicChatsLimit::ID): { return "checkCreatedPublicChatsLimit"; }
        case (td::td_api::checkDatabaseEncryptionKey::ID): { return "checkDatabaseEncryptionKey"; }
        case (td::td_api::checkEmailAddressVerificationCode::ID): { return "checkEmailAddressVerificationCode"; }
        case (td::td_api::checkPasswordRecoveryCode::ID): { return "checkPasswordRecoveryCode"; }
        case (td::td_api::checkPhoneNumberConfirmationCode::ID): { return "checkPhoneNumberConfirmationCode"; }
        case (td::td_api::checkPhoneNumberVerificationCode::ID): { return "checkPhoneNumberVerificationCode"; }
        case (td::td_api::checkRecoveryEmailAddressCode::ID): { return "checkRecoveryEmailAddressCode"; }
        case (td::td_api::checkStickerSetName::ID): { return "checkStickerSetName"; }
        case (td::td_api::cleanFileName::ID): { return "cleanFileName"; }
        case (td::td_api::clearAllDraftMessages::ID): { return "clearAllDraftMessages"; }
        case (td::td_api::clearImportedContacts::ID): { return "clearImportedContacts"; }
        case (td::td_api::clearRecentlyFoundChats::ID): { return "clearRecentlyFoundChats"; }
        case (td::td_api::clearRecentStickers::ID): { return "clearRecentStickers"; }
        case (td::td_api::clickAnimatedEmojiMessage::ID): { return "clickAnimatedEmojiMessage"; }
        case (td::td_api::close::ID): { return "close"; }
        case (td::td_api::ok::ID): { return "ok"; }
        case (td::td_api::error::ID): { return "error"; }
        case (td::td_api::closeChat::ID): { return "closeChat"; }
        case (td::td_api::closeSecretChat::ID): { return "closeSecretChat"; }
        case (td::td_api::confirmQrCodeAuthentication::ID): { return "confirmQrCodeAuthentication"; }
        case (td::td_api::createBasicGroupChat::ID): { return "createBasicGroupChat"; }
        case (td::td_api::createCall::ID): { return "createCall"; }
        case (td::td_api::createChatFilter::ID): { return "createChatFilter"; }
        case (td::td_api::createChatInviteLink::ID): { return "createChatInviteLink"; }
        case (td::td_api::createNewBasicGroupChat::ID): { return "createNewBasicGroupChat"; }
        case (td::td_api::createNewSecretChat::ID): { return "createNewSecretChat"; }
        case (td::td_api::createNewStickerSet::ID): { return "createNewStickerSet"; }
        case (td::td_api::createNewSupergroupChat::ID): { return "createNewSupergroupChat"; }
        case (td::td_api::createPrivateChat::ID): { return "createPrivateChat"; }
        case (td::td_api::createSecretChat::ID): { return "createSecretChat"; }
        case (td::td_api::createSupergroupChat::ID): { return "createSupergroupChat"; }
        case (td::td_api::createTemporaryPassword::ID): { return "createTemporaryPassword"; }
        case (td::td_api::createVideoChat::ID): { return "createVideoChat"; }
        case (td::td_api::deleteAccount::ID): { return "deleteAccount"; }
        case (td::td_api::deleteAllCallMessages::ID): { return "deleteAllCallMessages"; }
        case (td::td_api::deleteAllRevokedChatInviteLinks::ID): { return "deleteAllRevokedChatInviteLinks"; }
        case (td::td_api::deleteChat::ID): { return "deleteChat"; }
        case (td::td_api::deleteChatFilter::ID): { return "deleteChatFilter"; }
        case (td::td_api::deleteChatHistory::ID): { return "deleteChatHistory"; }
        case (td::td_api::deleteChatMessagesByDate::ID): { return "deleteChatMessagesByDate"; }
        case (td::td_api::deleteChatMessagesBySender::ID): { return "deleteChatMessagesBySender"; }
        case (td::td_api::deleteChatReplyMarkup::ID): { return "deleteChatReplyMarkup"; }
        case (td::td_api::deleteCommands::ID): { return "deleteCommands"; }
        case (td::td_api::deleteFile::ID): { return "deleteFile"; }
        case (td::td_api::deleteLanguagePack::ID): { return "deleteLanguagePack"; }
        case (td::td_api::deleteMessages::ID): { return "deleteMessages"; }
        case (td::td_api::deletePassportElement::ID): { return "deletePassportElement"; }
        case (td::td_api::deleteProfilePhoto::ID): { return "deleteProfilePhoto"; }
        case (td::td_api::deleteRevokedChatInviteLink::ID): { return "deleteRevokedChatInviteLink"; }
        case (td::td_api::deleteSavedCredentials::ID): { return "deleteSavedCredentials"; }
        case (td::td_api::deleteSavedOrderInfo::ID): { return "deleteSavedOrderInfo"; }
        case (td::td_api::destroy::ID): { return "destroy"; }
        case (td::td_api::disableProxy::ID): { return "disableProxy"; }
        case (td::td_api::discardCall::ID): { return "discardCall"; }
        case (td::td_api::disconnectAllWebsites::ID): { return "disconnectAllWebsites"; }
        case (td::td_api::disconnectWebsite::ID): { return "disconnectWebsite"; }
        case (td::td_api::downloadFile::ID): { return "downloadFile"; }
        case (td::td_api::editChatFilter::ID): { return "editChatFilter"; }
        case (td::td_api::editChatInviteLink::ID): { return "editChatInviteLink"; }
        case (td::td_api::editCustomLanguagePackInfo::ID): { return "editCustomLanguagePackInfo"; }
        case (td::td_api::editInlineMessageCaption::ID): { return "editInlineMessageCaption"; }
        case (td::td_api::editInlineMessageLiveLocation::ID): { return "editInlineMessageLiveLocation"; }
        case (td::td_api::editInlineMessageMedia::ID): { return "editInlineMessageMedia"; }
        case (td::td_api::editInlineMessageReplyMarkup::ID): { return "editInlineMessageReplyMarkup"; }
        case (td::td_api::editInlineMessageText::ID): { return "editInlineMessageText"; }
        case (td::td_api::editMessageCaption::ID): { return "editMessageCaption"; }
        case (td::td_api::editMessageLiveLocation::ID): { return "editMessageLiveLocation"; }
        case (td::td_api::editMessageMedia::ID): { return "editMessageMedia"; }
        case (td::td_api::editMessageReplyMarkup::ID): { return "editMessageReplyMarkup"; }
        case (td::td_api::editMessageSchedulingState::ID): { return "editMessageSchedulingState"; }
        case (td::td_api::editMessageText::ID): { return "editMessageText"; }
        case (td::td_api::editProxy::ID): { return "editProxy"; }
        case (td::td_api::enableProxy::ID): { return "enableProxy"; }
        case (td::td_api::endGroupCall::ID): { return "endGroupCall"; }
        case (td::td_api::endGroupCallRecording::ID): { return "endGroupCallRecording"; }
        case (td::td_api::endGroupCallScreenSharing::ID): { return "endGroupCallScreenSharing"; }
        case (td::td_api::finishFileGeneration::ID): { return "finishFileGeneration"; }
        case (td::td_api::forwardMessages::ID): { return "forwardMessages"; }
        case (td::td_api::getAccountTtl::ID): { return "getAccountTtl"; }
        case (td::td_api::getActiveLiveLocationMessages::ID): { return "getActiveLiveLocationMessages"; }
        case (td::td_api::getActiveSessions::ID): { return "getActiveSessions"; }
        case (td::td_api::getAllPassportElements::ID): { return "getAllPassportElements"; }
        case (td::td_api::getAnimatedEmoji::ID): { return "getAnimatedEmoji"; }
        case (td::td_api::getApplicationConfig::ID): { return "getApplicationConfig"; }
        case (td::td_api::getApplicationDownloadLink::ID): { return "getApplicationDownloadLink"; }
        case (td::td_api::getArchivedStickerSets::ID): { return "getArchivedStickerSets"; }
        case (td::td_api::getAttachedStickerSets::ID): { return "getAttachedStickerSets"; }
        case (td::td_api::getAuthorizationState::ID): { return "getAuthorizationState"; }
        case (td::td_api::getAutoDownloadSettingsPresets::ID): { return "getAutoDownloadSettingsPresets"; }
        case (td::td_api::getBackgrounds::ID): { return "getBackgrounds"; }
        case (td::td_api::getBackgroundUrl::ID): { return "getBackgroundUrl"; }
        case (td::td_api::getBankCardInfo::ID): { return "getBankCardInfo"; }
        case (td::td_api::getBasicGroup::ID): { return "getBasicGroup"; }
        case (td::td_api::getBasicGroupFullInfo::ID): { return "getBasicGroupFullInfo"; }
        case (td::td_api::getBlockedMessageSenders::ID): { return "getBlockedMessageSenders"; }
        case (td::td_api::getCallbackQueryAnswer::ID): { return "getCallbackQueryAnswer"; }
        case (td::td_api::getCallbackQueryMessage::ID): { return "getCallbackQueryMessage"; }
        case (td::td_api::getChat::ID): { return "getChat"; }
        case (td::td_api::getChatAdministrators::ID): { return "getChatAdministrators"; }
        case (td::td_api::getChatAvailableMessageSenders::ID): { return "getChatAvailableMessageSenders"; }
        case (td::td_api::getChatEventLog::ID): { return "getChatEventLog"; }
        case (td::td_api::getChatFilter::ID): { return "getChatFilter"; }
        case (td::td_api::getChatFilterDefaultIconName::ID): { return "getChatFilterDefaultIconName"; }
        case (td::td_api::getChatHistory::ID): { return "getChatHistory"; }
        case (td::td_api::getChatInviteLink::ID): { return "getChatInviteLink"; }
        case (td::td_api::getChatInviteLinkCounts::ID): { return "getChatInviteLinkCounts"; }
        case (td::td_api::getChatInviteLinkMembers::ID): { return "getChatInviteLinkMembers"; }
        case (td::td_api::getChatInviteLinks::ID): { return "getChatInviteLinks"; }
        case (td::td_api::getChatJoinRequests::ID): { return "getChatJoinRequests"; }
        case (td::td_api::getChatListsToAddChat::ID): { return "getChatListsToAddChat"; }
        case (td::td_api::getChatMember::ID): { return "getChatMember"; }
        case (td::td_api::getChatMessageByDate::ID): { return "getChatMessageByDate"; }
        case (td::td_api::getChatMessageCalendar::ID): { return "getChatMessageCalendar"; }
        case (td::td_api::getChatMessageCount::ID): { return "getChatMessageCount"; }
        case (td::td_api::getChatNotificationSettingsExceptions::ID): { return "getChatNotificationSettingsExceptions"; }
        case (td::td_api::getChatPinnedMessage::ID): { return "getChatPinnedMessage"; }
        case (td::td_api::getChats::ID): { return "getChats"; }
        case (td::td_api::getChatScheduledMessages::ID): { return "getChatScheduledMessages"; }
        case (td::td_api::getChatSparseMessagePositions::ID): { return "getChatSparseMessagePositions"; }
        case (td::td_api::getChatSponsoredMessage::ID): { return "getChatSponsoredMessage"; }
        case (td::td_api::getChatStatistics::ID): { return "getChatStatistics"; }
        case (td::td_api::getCommands::ID): { return "getCommands"; }
        case (td::td_api::getConnectedWebsites::ID): { return "getConnectedWebsites"; }
        case (td::td_api::getContacts::ID): { return "getContacts"; }
        case (td::td_api::getCountries::ID): { return "getCountries"; }
        case (td::td_api::getCountryCode::ID): { return "getCountryCode"; }
        case (td::td_api::getCreatedPublicChats::ID): { return "getCreatedPublicChats"; }
        case (td::td_api::getCurrentState::ID): { return "getCurrentState"; }
        case (td::td_api::getDatabaseStatistics::ID): { return "getDatabaseStatistics"; }
        case (td::td_api::getDeepLinkInfo::ID): { return "getDeepLinkInfo"; }
        case (td::td_api::getEmojiSuggestionsUrl::ID): { return "getEmojiSuggestionsUrl"; }
        case (td::td_api::getExternalLink::ID): { return "getExternalLink"; }
        case (td::td_api::getExternalLinkInfo::ID): { return "getExternalLinkInfo"; }
        case (td::td_api::getFavoriteStickers::ID): { return "getFavoriteStickers"; }
        case (td::td_api::getFile::ID): { return "getFile"; }
        case (td::td_api::getFileDownloadedPrefixSize::ID): { return "getFileDownloadedPrefixSize"; }
        case (td::td_api::getFileExtension::ID): { return "getFileExtension"; }
        case (td::td_api::getFileMimeType::ID): { return "getFileMimeType"; }
        case (td::td_api::getGameHighScores::ID): { return "getGameHighScores"; }
        case (td::td_api::getGroupCall::ID): { return "getGroupCall"; }
        case (td::td_api::getGroupCallInviteLink::ID): { return "getGroupCallInviteLink"; }
        case (td::td_api::getGroupCallStreamSegment::ID): { return "getGroupCallStreamSegment"; }
        case (td::td_api::getGroupsInCommon::ID): { return "getGroupsInCommon"; }
        case (td::td_api::getImportedContactCount::ID): { return "getImportedContactCount"; }
        case (td::td_api::getInactiveSupergroupChats::ID): { return "getInactiveSupergroupChats"; }
        case (td::td_api::getInlineGameHighScores::ID): { return "getInlineGameHighScores"; }
        case (td::td_api::getInlineQueryResults::ID): { return "getInlineQueryResults"; }
        case (td::td_api::getInstalledStickerSets::ID): { return "getInstalledStickerSets"; }
        case (td::td_api::getInternalLinkType::ID): { return "getInternalLinkType"; }
        case (td::td_api::getJsonString::ID): { return "getJsonString"; }
        case (td::td_api::getJsonValue::ID): { return "getJsonValue"; }
        case (td::td_api::getLanguagePackInfo::ID): { return "getLanguagePackInfo"; }
        case (td::td_api::getLanguagePackString::ID): { return "getLanguagePackString"; }
        case (td::td_api::getLanguagePackStrings::ID): { return "getLanguagePackStrings"; }
        case (td::td_api::getLocalizationTargetInfo::ID): { return "getLocalizationTargetInfo"; }
        case (td::td_api::getLoginUrl::ID): { return "getLoginUrl"; }
        case (td::td_api::getLoginUrlInfo::ID): { return "getLoginUrlInfo"; }
        case (td::td_api::getLogStream::ID): { return "getLogStream"; }
        case (td::td_api::getLogTags::ID): { return "getLogTags"; }
        case (td::td_api::getLogTagVerbosityLevel::ID): { return "getLogTagVerbosityLevel"; }
        case (td::td_api::getLogVerbosityLevel::ID): { return "getLogVerbosityLevel"; }
        case (td::td_api::getMapThumbnailFile::ID): { return "getMapThumbnailFile"; }
        case (td::td_api::getMarkdownText::ID): { return "getMarkdownText"; }
        case (td::td_api::getMe::ID): { return "getMe"; }
        case (td::td_api::getMessage::ID): { return "getMessage"; }
        case (td::td_api::getMessageEmbeddingCode::ID): { return "getMessageEmbeddingCode"; }
        case (td::td_api::getMessageFileType::ID): { return "getMessageFileType"; }
        case (td::td_api::getMessageImportConfirmationText::ID): { return "getMessageImportConfirmationText"; }
        case (td::td_api::getMessageLink::ID): { return "getMessageLink"; }
        case (td::td_api::getMessageLinkInfo::ID): { return "getMessageLinkInfo"; }
        case (td::td_api::getMessageLocally::ID): { return "getMessageLocally"; }
        case (td::td_api::getMessagePublicForwards::ID): { return "getMessagePublicForwards"; }
        case (td::td_api::getMessages::ID): { return "getMessages"; }
        case (td::td_api::getMessageStatistics::ID): { return "getMessageStatistics"; }
        case (td::td_api::getMessageThread::ID): { return "getMessageThread"; }
        case (td::td_api::getMessageThreadHistory::ID): { return "getMessageThreadHistory"; }
        case (td::td_api::getMessageViewers::ID): { return "getMessageViewers"; }
        case (td::td_api::getNetworkStatistics::ID): { return "getNetworkStatistics"; }
        case (td::td_api::getOption::ID): { return "getOption"; }
        case (td::td_api::getPassportAuthorizationForm::ID): { return "getPassportAuthorizationForm"; }
        case (td::td_api::getPassportAuthorizationFormAvailableElements::ID): { return "getPassportAuthorizationFormAvailableElements"; }
        case (td::td_api::getPassportElement::ID): { return "getPassportElement"; }
        case (td::td_api::getPasswordState::ID): { return "getPasswordState"; }
        case (td::td_api::getPaymentForm::ID): { return "getPaymentForm"; }
        case (td::td_api::getPaymentReceipt::ID): { return "getPaymentReceipt"; }
        case (td::td_api::getPhoneNumberInfo::ID): { return "getPhoneNumberInfo"; }
        case (td::td_api::getPhoneNumberInfoSync::ID): { return "getPhoneNumberInfoSync"; }
        case (td::td_api::getPollVoters::ID): { return "getPollVoters"; }
        case (td::td_api::getPreferredCountryLanguage::ID): { return "getPreferredCountryLanguage"; }
        case (td::td_api::getProxies::ID): { return "getProxies"; }
        case (td::td_api::getProxyLink::ID): { return "getProxyLink"; }
        case (td::td_api::getPushReceiverId::ID): { return "getPushReceiverId"; }
        case (td::td_api::getRecentInlineBots::ID): { return "getRecentInlineBots"; }
        case (td::td_api::getRecentlyOpenedChats::ID): { return "getRecentlyOpenedChats"; }
        case (td::td_api::getRecentlyVisitedTMeUrls::ID): { return "getRecentlyVisitedTMeUrls"; }
        case (td::td_api::getRecentStickers::ID): { return "getRecentStickers"; }
        case (td::td_api::getRecommendedChatFilters::ID): { return "getRecommendedChatFilters"; }
        case (td::td_api::getRecoveryEmailAddress::ID): { return "getRecoveryEmailAddress"; }
        case (td::td_api::getRemoteFile::ID): { return "getRemoteFile"; }
        case (td::td_api::getRepliedMessage::ID): { return "getRepliedMessage"; }
        case (td::td_api::getSavedAnimations::ID): { return "getSavedAnimations"; }
        case (td::td_api::getSavedOrderInfo::ID): { return "getSavedOrderInfo"; }
        case (td::td_api::getScopeNotificationSettings::ID): { return "getScopeNotificationSettings"; }
        case (td::td_api::getSecretChat::ID): { return "getSecretChat"; }
        case (td::td_api::getStatisticalGraph::ID): { return "getStatisticalGraph"; }
        case (td::td_api::getStickerEmojis::ID): { return "getStickerEmojis"; }
        case (td::td_api::getStickers::ID): { return "getStickers"; }
        case (td::td_api::getStickerSet::ID): { return "getStickerSet"; }
        case (td::td_api::getStorageStatistics::ID): { return "getStorageStatistics"; }
        case (td::td_api::getStorageStatisticsFast::ID): { return "getStorageStatisticsFast"; }
        case (td::td_api::getSuggestedFileName::ID): { return "getSuggestedFileName"; }
        case (td::td_api::getSuggestedStickerSetName::ID): { return "getSuggestedStickerSetName"; }
        case (td::td_api::getSuitableDiscussionChats::ID): { return "getSuitableDiscussionChats"; }
        case (td::td_api::getSupergroup::ID): { return "getSupergroup"; }
        case (td::td_api::getSupergroupFullInfo::ID): { return "getSupergroupFullInfo"; }
        case (td::td_api::getSupergroupMembers::ID): { return "getSupergroupMembers"; }
        case (td::td_api::getSupportUser::ID): { return "getSupportUser"; }
        case (td::td_api::getTemporaryPasswordState::ID): { return "getTemporaryPasswordState"; }
        case (td::td_api::getTextEntities::ID): { return "getTextEntities"; }
        case (td::td_api::getTopChats::ID): { return "getTopChats"; }
        case (td::td_api::getTrendingStickerSets::ID): { return "getTrendingStickerSets"; }
        case (td::td_api::getUser::ID): { return "getUser"; }
        case (td::td_api::getUserFullInfo::ID): { return "getUserFullInfo"; }
        case (td::td_api::getUserPrivacySettingRules::ID): { return "getUserPrivacySettingRules"; }
        case (td::td_api::getUserProfilePhotos::ID): { return "getUserProfilePhotos"; }
        case (td::td_api::getVideoChatAvailableParticipants::ID): { return "getVideoChatAvailableParticipants"; }
        case (td::td_api::getWebPageInstantView::ID): { return "getWebPageInstantView"; }
        case (td::td_api::getWebPagePreview::ID): { return "getWebPagePreview"; }
        case (td::td_api::hideSuggestedAction::ID): { return "hideSuggestedAction"; }
        case (td::td_api::importContacts::ID): { return "importContacts"; }
        case (td::td_api::importMessages::ID): { return "importMessages"; }
        case (td::td_api::inviteGroupCallParticipants::ID): { return "inviteGroupCallParticipants"; }
        case (td::td_api::joinChat::ID): { return "joinChat"; }
        case (td::td_api::joinChatByInviteLink::ID): { return "joinChatByInviteLink"; }
        case (td::td_api::joinGroupCall::ID): { return "joinGroupCall"; }
        case (td::td_api::leaveChat::ID): { return "leaveChat"; }
        case (td::td_api::leaveGroupCall::ID): { return "leaveGroupCall"; }
        case (td::td_api::loadChats::ID): { return "loadChats"; }
        case (td::td_api::loadGroupCallParticipants::ID): { return "loadGroupCallParticipants"; }
        case (td::td_api::logOut::ID): { return "logOut"; }
        case (td::td_api::openChat::ID): { return "openChat"; }
        case (td::td_api::openMessageContent::ID): { return "openMessageContent"; }
        case (td::td_api::optimizeStorage::ID): { return "optimizeStorage"; }
        case (td::td_api::parseMarkdown::ID): { return "parseMarkdown"; }
        case (td::td_api::parseTextEntities::ID): { return "parseTextEntities"; }
        case (td::td_api::pinChatMessage::ID): { return "pinChatMessage"; }
        case (td::td_api::pingProxy::ID): { return "pingProxy"; }
        case (td::td_api::processChatJoinRequest::ID): { return "processChatJoinRequest"; }
        case (td::td_api::processChatJoinRequests::ID): { return "processChatJoinRequests"; }
        case (td::td_api::processPushNotification::ID): { return "processPushNotification"; }
        case (td::td_api::readAllChatMentions::ID): { return "readAllChatMentions"; }
        case (td::td_api::readFilePart::ID): { return "readFilePart"; }
        case (td::td_api::recoverAuthenticationPassword::ID): { return "recoverAuthenticationPassword"; }
        case (td::td_api::recoverPassword::ID): { return "recoverPassword"; }
        case (td::td_api::registerDevice::ID): { return "registerDevice"; }
        case (td::td_api::registerUser::ID): { return "registerUser"; }
        case (td::td_api::removeBackground::ID): { return "removeBackground"; }
        case (td::td_api::removeChatActionBar::ID): { return "removeChatActionBar"; }
        case (td::td_api::removeContacts::ID): { return "removeContacts"; }
        case (td::td_api::removeFavoriteSticker::ID): { return "removeFavoriteSticker"; }
        case (td::td_api::removeNotification::ID): { return "removeNotification"; }
        case (td::td_api::removeNotificationGroup::ID): { return "removeNotificationGroup"; }
        case (td::td_api::removeProxy::ID): { return "removeProxy"; }
        case (td::td_api::removeRecentHashtag::ID): { return "removeRecentHashtag"; }
        case (td::td_api::removeRecentlyFoundChat::ID): { return "removeRecentlyFoundChat"; }
        case (td::td_api::removeRecentSticker::ID): { return "removeRecentSticker"; }
        case (td::td_api::removeSavedAnimation::ID): { return "removeSavedAnimation"; }
        case (td::td_api::removeStickerFromSet::ID): { return "removeStickerFromSet"; }
        case (td::td_api::removeTopChat::ID): { return "removeTopChat"; }
        case (td::td_api::reorderChatFilters::ID): { return "reorderChatFilters"; }
        case (td::td_api::reorderInstalledStickerSets::ID): { return "reorderInstalledStickerSets"; }
        case (td::td_api::replacePrimaryChatInviteLink::ID): { return "replacePrimaryChatInviteLink"; }
        case (td::td_api::reportChat::ID): { return "reportChat"; }
        case (td::td_api::reportChatPhoto::ID): { return "reportChatPhoto"; }
        case (td::td_api::reportSupergroupSpam::ID): { return "reportSupergroupSpam"; }
        case (td::td_api::requestAuthenticationPasswordRecovery::ID): { return "requestAuthenticationPasswordRecovery"; }
        case (td::td_api::requestPasswordRecovery::ID): { return "requestPasswordRecovery"; }
        case (td::td_api::requestQrCodeAuthentication::ID): { return "requestQrCodeAuthentication"; }
        case (td::td_api::resendAuthenticationCode::ID): { return "resendAuthenticationCode"; }
        case (td::td_api::resendChangePhoneNumberCode::ID): { return "resendChangePhoneNumberCode"; }
        case (td::td_api::resendEmailAddressVerificationCode::ID): { return "resendEmailAddressVerificationCode"; }
        case (td::td_api::resendMessages::ID): { return "resendMessages"; }
        case (td::td_api::resendPhoneNumberConfirmationCode::ID): { return "resendPhoneNumberConfirmationCode"; }
        case (td::td_api::resendPhoneNumberVerificationCode::ID): { return "resendPhoneNumberVerificationCode"; }
        case (td::td_api::resendRecoveryEmailAddressCode::ID): { return "resendRecoveryEmailAddressCode"; }
        case (td::td_api::resetAllNotificationSettings::ID): { return "resetAllNotificationSettings"; }
        case (td::td_api::resetBackgrounds::ID): { return "resetBackgrounds"; }
        case (td::td_api::resetNetworkStatistics::ID): { return "resetNetworkStatistics"; }
        case (td::td_api::resetPassword::ID): { return "resetPassword"; }
        case (td::td_api::revokeChatInviteLink::ID): { return "revokeChatInviteLink"; }
        case (td::td_api::revokeGroupCallInviteLink::ID): { return "revokeGroupCallInviteLink"; }
        case (td::td_api::saveApplicationLogEvent::ID): { return "saveApplicationLogEvent"; }
        case (td::td_api::searchBackground::ID): { return "searchBackground"; }
        case (td::td_api::searchCallMessages::ID): { return "searchCallMessages"; }
        case (td::td_api::searchChatMembers::ID): { return "searchChatMembers"; }
        case (td::td_api::searchChatMessages::ID): { return "searchChatMessages"; }
        case (td::td_api::searchChatRecentLocationMessages::ID): { return "searchChatRecentLocationMessages"; }
        case (td::td_api::searchChats::ID): { return "searchChats"; }
        case (td::td_api::searchChatsNearby::ID): { return "searchChatsNearby"; }
        case (td::td_api::searchChatsOnServer::ID): { return "searchChatsOnServer"; }
        case (td::td_api::searchContacts::ID): { return "searchContacts"; }
        case (td::td_api::searchEmojis::ID): { return "searchEmojis"; }
        case (td::td_api::searchHashtags::ID): { return "searchHashtags"; }
        case (td::td_api::searchInstalledStickerSets::ID): { return "searchInstalledStickerSets"; }
        case (td::td_api::searchMessages::ID): { return "searchMessages"; }
        case (td::td_api::searchPublicChat::ID): { return "searchPublicChat"; }
        case (td::td_api::searchPublicChats::ID): { return "searchPublicChats"; }
        case (td::td_api::searchSecretMessages::ID): { return "searchSecretMessages"; }
        case (td::td_api::searchStickers::ID): { return "searchStickers"; }
        case (td::td_api::searchStickerSet::ID): { return "searchStickerSet"; }
        case (td::td_api::searchStickerSets::ID): { return "searchStickerSets"; }
        case (td::td_api::sendBotStartMessage::ID): { return "sendBotStartMessage"; }
        case (td::td_api::sendCallDebugInformation::ID): { return "sendCallDebugInformation"; }
        case (td::td_api::sendCallRating::ID): { return "sendCallRating"; }
        case (td::td_api::sendCallSignalingData::ID): { return "sendCallSignalingData"; }
        case (td::td_api::sendChatAction::ID): { return "sendChatAction"; }
        case (td::td_api::sendChatScreenshotTakenNotification::ID): { return "sendChatScreenshotTakenNotification"; }
        case (td::td_api::sendCustomRequest::ID): { return "sendCustomRequest"; }
        case (td::td_api::sendEmailAddressVerificationCode::ID): { return "sendEmailAddressVerificationCode"; }
        case (td::td_api::sendInlineQueryResultMessage::ID): { return "sendInlineQueryResultMessage"; }
        case (td::td_api::sendMessage::ID): { return "sendMessage"; }
        case (td::td_api::sendMessageAlbum::ID): { return "sendMessageAlbum"; }
        case (td::td_api::sendPassportAuthorizationForm::ID): { return "sendPassportAuthorizationForm"; }
        case (td::td_api::sendPaymentForm::ID): { return "sendPaymentForm"; }
        case (td::td_api::sendPhoneNumberConfirmationCode::ID): { return "sendPhoneNumberConfirmationCode"; }
        case (td::td_api::sendPhoneNumberVerificationCode::ID): { return "sendPhoneNumberVerificationCode"; }
        case (td::td_api::setAccountTtl::ID): { return "setAccountTtl"; }
        case (td::td_api::setAlarm::ID): { return "setAlarm"; }
        case (td::td_api::setAuthenticationPhoneNumber::ID): { return "setAuthenticationPhoneNumber"; }
        case (td::td_api::setAutoDownloadSettings::ID): { return "setAutoDownloadSettings"; }
        case (td::td_api::setBackground::ID): { return "setBackground"; }
        case (td::td_api::setBio::ID): { return "setBio"; }
        case (td::td_api::setBotUpdatesStatus::ID): { return "setBotUpdatesStatus"; }
        case (td::td_api::setChatClientData::ID): { return "setChatClientData"; }
        case (td::td_api::setChatDescription::ID): { return "setChatDescription"; }
        case (td::td_api::setChatDiscussionGroup::ID): { return "setChatDiscussionGroup"; }
        case (td::td_api::setChatDraftMessage::ID): { return "setChatDraftMessage"; }
        case (td::td_api::setChatLocation::ID): { return "setChatLocation"; }
        case (td::td_api::setChatMemberStatus::ID): { return "setChatMemberStatus"; }
        case (td::td_api::setChatMessageSender::ID): { return "setChatMessageSender"; }
        case (td::td_api::setChatMessageTtl::ID): { return "setChatMessageTtl"; }
        case (td::td_api::setChatNotificationSettings::ID): { return "setChatNotificationSettings"; }
        case (td::td_api::setChatPermissions::ID): { return "setChatPermissions"; }
        case (td::td_api::setChatPhoto::ID): { return "setChatPhoto"; }
        case (td::td_api::setChatSlowModeDelay::ID): { return "setChatSlowModeDelay"; }
        case (td::td_api::setChatTheme::ID): { return "setChatTheme"; }
        case (td::td_api::setChatTitle::ID): { return "setChatTitle"; }
        case (td::td_api::setCommands::ID): { return "setCommands"; }
        case (td::td_api::setCustomLanguagePack::ID): { return "setCustomLanguagePack"; }
        case (td::td_api::setCustomLanguagePackString::ID): { return "setCustomLanguagePackString"; }
        case (td::td_api::setDatabaseEncryptionKey::ID): { return "setDatabaseEncryptionKey"; }
        case (td::td_api::setFileGenerationProgress::ID): { return "setFileGenerationProgress"; }
        case (td::td_api::setGameScore::ID): { return "setGameScore"; }
        case (td::td_api::setGroupCallParticipantIsSpeaking::ID): { return "setGroupCallParticipantIsSpeaking"; }
        case (td::td_api::setGroupCallParticipantVolumeLevel::ID): { return "setGroupCallParticipantVolumeLevel"; }
        case (td::td_api::setGroupCallTitle::ID): { return "setGroupCallTitle"; }
        case (td::td_api::setInactiveSessionTtl::ID): { return "setInactiveSessionTtl"; }
        case (td::td_api::setInlineGameScore::ID): { return "setInlineGameScore"; }
        case (td::td_api::setLocation::ID): { return "setLocation"; }
        case (td::td_api::setLogStream::ID): { return "setLogStream"; }
        case (td::td_api::setLogTagVerbosityLevel::ID): { return "setLogTagVerbosityLevel"; }
        case (td::td_api::setLogVerbosityLevel::ID): { return "setLogVerbosityLevel"; }
        case (td::td_api::setName::ID): { return "setName"; }
        case (td::td_api::setNetworkType::ID): { return "setNetworkType"; }
        case (td::td_api::setOption::ID): { return "setOption"; }
        case (td::td_api::setPassportElement::ID): { return "setPassportElement"; }
        case (td::td_api::setPassportElementErrors::ID): { return "setPassportElementErrors"; }
        case (td::td_api::setPassword::ID): { return "setPassword"; }
        case (td::td_api::setPinnedChats::ID): { return "setPinnedChats"; }
        case (td::td_api::setPollAnswer::ID): { return "setPollAnswer"; }
        case (td::td_api::setProfilePhoto::ID): { return "setProfilePhoto"; }
        case (td::td_api::setRecoveryEmailAddress::ID): { return "setRecoveryEmailAddress"; }
        case (td::td_api::setScopeNotificationSettings::ID): { return "setScopeNotificationSettings"; }
        case (td::td_api::setStickerPositionInSet::ID): { return "setStickerPositionInSet"; }
        case (td::td_api::setStickerSetThumbnail::ID): { return "setStickerSetThumbnail"; }
        case (td::td_api::setSupergroupStickerSet::ID): { return "setSupergroupStickerSet"; }
        case (td::td_api::setSupergroupUsername::ID): { return "setSupergroupUsername"; }
        case (td::td_api::setTdlibParameters::ID): { return "setTdlibParameters"; }
        case (td::td_api::setUsername::ID): { return "setUsername"; }
        case (td::td_api::setUserPrivacySettingRules::ID): { return "setUserPrivacySettingRules"; }
        case (td::td_api::setVideoChatDefaultParticipant::ID): { return "setVideoChatDefaultParticipant"; }
        case (td::td_api::sharePhoneNumber::ID): { return "sharePhoneNumber"; }
        case (td::td_api::startGroupCallRecording::ID): { return "startGroupCallRecording"; }
        case (td::td_api::startGroupCallScreenSharing::ID): { return "startGroupCallScreenSharing"; }
        case (td::td_api::startScheduledGroupCall::ID): { return "startScheduledGroupCall"; }
        case (td::td_api::stopPoll::ID): { return "stopPoll"; }
        case (td::td_api::synchronizeLanguagePack::ID): { return "synchronizeLanguagePack"; }
        case (td::td_api::terminateAllOtherSessions::ID): { return "terminateAllOtherSessions"; }
        case (td::td_api::terminateSession::ID): { return "terminateSession"; }
        case (td::td_api::testCallBytes::ID): { return "testCallBytes"; }
        case (td::td_api::testCallEmpty::ID): { return "testCallEmpty"; }
        case (td::td_api::testCallString::ID): { return "testCallString"; }
        case (td::td_api::testCallVectorInt::ID): { return "testCallVectorInt"; }
        case (td::td_api::testCallVectorIntObject::ID): { return "testCallVectorIntObject"; }
        case (td::td_api::testCallVectorString::ID): { return "testCallVectorString"; }
        case (td::td_api::testCallVectorStringObject::ID): { return "testCallVectorStringObject"; }
        case (td::td_api::testGetDifference::ID): { return "testGetDifference"; }
        case (td::td_api::testNetwork::ID): { return "testNetwork"; }
        case (td::td_api::testProxy::ID): { return "testProxy"; }
        case (td::td_api::testReturnError::ID): { return "testReturnError"; }
        case (td::td_api::testSquareInt::ID): { return "testSquareInt"; }
        case (td::td_api::testUseUpdate::ID): { return "testUseUpdate"; }
        case (td::td_api::toggleChatDefaultDisableNotification::ID): { return "toggleChatDefaultDisableNotification"; }
        case (td::td_api::toggleChatHasProtectedContent::ID): { return "toggleChatHasProtectedContent"; }
        case (td::td_api::toggleChatIsMarkedAsUnread::ID): { return "toggleChatIsMarkedAsUnread"; }
        case (td::td_api::toggleChatIsPinned::ID): { return "toggleChatIsPinned"; }
        case (td::td_api::toggleGroupCallEnabledStartNotification::ID): { return "toggleGroupCallEnabledStartNotification"; }
        case (td::td_api::toggleGroupCallIsMyVideoEnabled::ID): { return "toggleGroupCallIsMyVideoEnabled"; }
        case (td::td_api::toggleGroupCallIsMyVideoPaused::ID): { return "toggleGroupCallIsMyVideoPaused"; }
        case (td::td_api::toggleGroupCallMuteNewParticipants::ID): { return "toggleGroupCallMuteNewParticipants"; }
        case (td::td_api::toggleGroupCallParticipantIsHandRaised::ID): { return "toggleGroupCallParticipantIsHandRaised"; }
        case (td::td_api::toggleGroupCallParticipantIsMuted::ID): { return "toggleGroupCallParticipantIsMuted"; }
        case (td::td_api::toggleGroupCallScreenSharingIsPaused::ID): { return "toggleGroupCallScreenSharingIsPaused"; }
        case (td::td_api::toggleMessageSenderIsBlocked::ID): { return "toggleMessageSenderIsBlocked"; }
        case (td::td_api::toggleSessionCanAcceptCalls::ID): { return "toggleSessionCanAcceptCalls"; }
        case (td::td_api::toggleSessionCanAcceptSecretChats::ID): { return "toggleSessionCanAcceptSecretChats"; }
        case (td::td_api::toggleSupergroupIsAllHistoryAvailable::ID): { return "toggleSupergroupIsAllHistoryAvailable"; }
        case (td::td_api::toggleSupergroupIsBroadcastGroup::ID): { return "toggleSupergroupIsBroadcastGroup"; }
        case (td::td_api::toggleSupergroupSignMessages::ID): { return "toggleSupergroupSignMessages"; }
        case (td::td_api::transferChatOwnership::ID): { return "transferChatOwnership"; }
        case (td::td_api::unpinAllChatMessages::ID): { return "unpinAllChatMessages"; }
        case (td::td_api::unpinChatMessage::ID): { return "unpinChatMessage"; }
        case (td::td_api::upgradeBasicGroupChatToSupergroupChat::ID): { return "upgradeBasicGroupChatToSupergroupChat"; }
        case (td::td_api::uploadFile::ID): { return "uploadFile"; }
        case (td::td_api::uploadStickerFile::ID): { return "uploadStickerFile"; }
        case (td::td_api::validateOrderInfo::ID): { return "validateOrderInfo"; }
        case (td::td_api::viewMessages::ID): { return "viewMessages"; }
        case (td::td_api::viewTrendingStickerSets::ID): { return "viewTrendingStickerSets"; }
        case (td::td_api::writeGeneratedFilePart::ID): { return "writeGeneratedFilePart"; }
        case (td::td_api::updateActiveNotifications::ID): { return "updateActiveNotifications"; }
        case (td::td_api::updateAnimatedEmojiMessageClicked::ID): { return "updateAnimatedEmojiMessageClicked"; }
        case (td::td_api::updateAnimationSearchParameters::ID): { return "updateAnimationSearchParameters"; }
        case (td::td_api::updateAuthorizationState::ID): { return "updateAuthorizationState"; }
        case (td::td_api::authorizationStateWaitTdlibParameters::ID): { return "authorizationStateWaitTdlibParameters"; }
        case (td::td_api::authorizationStateWaitEncryptionKey::ID): { return "authorizationStateWaitEncryptionKey"; }
        case (td::td_api::authorizationStateWaitPhoneNumber::ID): { return "authorizationStateWaitPhoneNumber"; }
        case (td::td_api::authorizationStateWaitCode::ID): { return "authorizationStateWaitCode"; }
        case (td::td_api::authorizationStateWaitOtherDeviceConfirmation::ID): { return "authorizationStateWaitOtherDeviceConfirmation"; }
        case (td::td_api::authorizationStateWaitRegistration::ID): { return "authorizationStateWaitRegistration"; }
        case (td::td_api::authorizationStateWaitPassword::ID): { return "authorizationStateWaitPassword"; }
        case (td::td_api::authorizationStateReady::ID): { return "authorizationStateReady"; }
        case (td::td_api::authorizationStateLoggingOut::ID): { return "authorizationStateLoggingOut"; }
        case (td::td_api::authorizationStateClosing::ID): { return "authorizationStateClosing"; }
        case (td::td_api::authorizationStateClosed::ID): { return "authorizationStateClosed"; }
        case (td::td_api::updateBasicGroup::ID): { return "updateBasicGroup"; }
        case (td::td_api::updateBasicGroupFullInfo::ID): { return "updateBasicGroupFullInfo"; }
        case (td::td_api::updateCall::ID): { return "updateCall"; }
        case (td::td_api::updateChatAction::ID): { return "updateChatAction"; }
        case (td::td_api::updateChatActionBar::ID): { return "updateChatActionBar"; }
        case (td::td_api::updateChatDefaultDisableNotification::ID): { return "updateChatDefaultDisableNotification"; }
        case (td::td_api::updateChatDraftMessage::ID): { return "updateChatDraftMessage"; }
        case (td::td_api::updateChatFilters::ID): { return "updateChatFilters"; }
        case (td::td_api::updateChatHasProtectedContent::ID): { return "updateChatHasProtectedContent"; }
        case (td::td_api::updateChatHasScheduledMessages::ID): { return "updateChatHasScheduledMessages"; }
        case (td::td_api::updateChatIsBlocked::ID): { return "updateChatIsBlocked"; }
        case (td::td_api::updateChatIsMarkedAsUnread::ID): { return "updateChatIsMarkedAsUnread"; }
        case (td::td_api::updateChatLastMessage::ID): { return "updateChatLastMessage"; }
        case (td::td_api::updateChatMember::ID): { return "updateChatMember"; }
        case (td::td_api::updateChatMessageSender::ID): { return "updateChatMessageSender"; }
        case (td::td_api::updateChatMessageTtl::ID): { return "updateChatMessageTtl"; }
        case (td::td_api::updateChatNotificationSettings::ID): { return "updateChatNotificationSettings"; }
        case (td::td_api::updateChatOnlineMemberCount::ID): { return "updateChatOnlineMemberCount"; }
        case (td::td_api::updateChatPendingJoinRequests::ID): { return "updateChatPendingJoinRequests"; }
        case (td::td_api::updateChatPermissions::ID): { return "updateChatPermissions"; }
        case (td::td_api::updateChatPhoto::ID): { return "updateChatPhoto"; }
        case (td::td_api::updateChatPosition::ID): { return "updateChatPosition"; }
        case (td::td_api::updateChatReadInbox::ID): { return "updateChatReadInbox"; }
        case (td::td_api::updateChatReadOutbox::ID): { return "updateChatReadOutbox"; }
        case (td::td_api::updateChatReplyMarkup::ID): { return "updateChatReplyMarkup"; }
        case (td::td_api::updateChatTheme::ID): { return "updateChatTheme"; }
        case (td::td_api::updateChatThemes::ID): { return "updateChatThemes"; }
        case (td::td_api::updateChatTitle::ID): { return "updateChatTitle"; }
        case (td::td_api::updateChatUnreadMentionCount::ID): { return "updateChatUnreadMentionCount"; }
        case (td::td_api::updateChatVideoChat::ID): { return "updateChatVideoChat"; }
        case (td::td_api::updateConnectionState::ID): { return "updateConnectionState"; }
        case (td::td_api::updateDeleteMessages::ID): { return "updateDeleteMessages"; }
        case (td::td_api::updateDiceEmojis::ID): { return "updateDiceEmojis"; }
        case (td::td_api::updateFavoriteStickers::ID): { return "updateFavoriteStickers"; }
        case (td::td_api::updateFile::ID): { return "updateFile"; }
        case (td::td_api::updateFileDownloads::ID): { return "updateFileDownloads"; }
        case (td::td_api::updateFileGenerationStart::ID): { return "updateFileGenerationStart"; }
        case (td::td_api::updateFileGenerationStop::ID): { return "updateFileGenerationStop"; }
        case (td::td_api::updateGroupCall::ID): { return "updateGroupCall"; }
        case (td::td_api::updateGroupCallParticipant::ID): { return "updateGroupCallParticipant"; }
        case (td::td_api::updateHavePendingNotifications::ID): { return "updateHavePendingNotifications"; }
        case (td::td_api::updateInstalledStickerSets::ID): { return "updateInstalledStickerSets"; }
        case (td::td_api::updateLanguagePackStrings::ID): { return "updateLanguagePackStrings"; }
        case (td::td_api::updateMessageContent::ID): { return "updateMessageContent"; }
        case (td::td_api::updateMessageContentOpened::ID): { return "updateMessageContentOpened"; }
        case (td::td_api::updateMessageEdited::ID): { return "updateMessageEdited"; }
        case (td::td_api::updateMessageInteractionInfo::ID): { return "updateMessageInteractionInfo"; }
        case (td::td_api::updateMessageIsPinned::ID): { return "updateMessageIsPinned"; }
        case (td::td_api::updateMessageLiveLocationViewed::ID): { return "updateMessageLiveLocationViewed"; }
        case (td::td_api::updateMessageMentionRead::ID): { return "updateMessageMentionRead"; }
        case (td::td_api::updateMessageSendAcknowledged::ID): { return "updateMessageSendAcknowledged"; }
        case (td::td_api::updateMessageSendFailed::ID): { return "updateMessageSendFailed"; }
        case (td::td_api::updateMessageSendSucceeded::ID): { return "updateMessageSendSucceeded"; }
        case (td::td_api::updateNewCallbackQuery::ID): { return "updateNewCallbackQuery"; }
        case (td::td_api::updateNewCallSignalingData::ID): { return "updateNewCallSignalingData"; }
        case (td::td_api::updateNewChat::ID): { return "updateNewChat"; }
        case (td::td_api::updateNewChatJoinRequest::ID): { return "updateNewChatJoinRequest"; }
        case (td::td_api::updateNewChosenInlineResult::ID): { return "updateNewChosenInlineResult"; }
        case (td::td_api::updateNewCustomEvent::ID): { return "updateNewCustomEvent"; }
        case (td::td_api::updateNewCustomQuery::ID): { return "updateNewCustomQuery"; }
        case (td::td_api::updateNewInlineCallbackQuery::ID): { return "updateNewInlineCallbackQuery"; }
        case (td::td_api::updateNewInlineQuery::ID): { return "updateNewInlineQuery"; }
        case (td::td_api::updateNewMessage::ID): { return "updateNewMessage"; }
        case (td::td_api::updateNewPreCheckoutQuery::ID): { return "updateNewPreCheckoutQuery"; }
        case (td::td_api::updateNewShippingQuery::ID): { return "updateNewShippingQuery"; }
        case (td::td_api::updateNotification::ID): { return "updateNotification"; }
        case (td::td_api::updateNotificationGroup::ID): { return "updateNotificationGroup"; }
        case (td::td_api::updateOption::ID): { return "updateOption"; }
        case (td::td_api::updatePoll::ID): { return "updatePoll"; }
        case (td::td_api::updatePollAnswer::ID): { return "updatePollAnswer"; }
        case (td::td_api::updateRecentStickers::ID): { return "updateRecentStickers"; }
        case (td::td_api::updateSavedAnimations::ID): { return "updateSavedAnimations"; }
        case (td::td_api::updateScopeNotificationSettings::ID): { return "updateScopeNotificationSettings"; }
        case (td::td_api::updateSecretChat::ID): { return "updateSecretChat"; }
        case (td::td_api::updateSelectedBackground::ID): { return "updateSelectedBackground"; }
        case (td::td_api::updateServiceNotification::ID): { return "updateServiceNotification"; }
        case (td::td_api::updateStickerSet::ID): { return "updateStickerSet"; }
        case (td::td_api::updateSuggestedActions::ID): { return "updateSuggestedActions"; }
        case (td::td_api::updateSupergroup::ID): { return "updateSupergroup"; }
        case (td::td_api::updateSupergroupFullInfo::ID): { return "updateSupergroupFullInfo"; }
        case (td::td_api::updateTermsOfService::ID): { return "updateTermsOfService"; }
        case (td::td_api::updateTrendingStickerSets::ID): { return "updateTrendingStickerSets"; }
        case (td::td_api::updateUnreadChatCount::ID): { return "updateUnreadChatCount"; }
        case (td::td_api::updateUnreadMessageCount::ID): { return "updateUnreadMessageCount"; }
        case (td::td_api::updateUser::ID): { return "updateUser"; }
        case (td::td_api::updateUserFullInfo::ID): { return "updateUserFullInfo"; }
        case (td::td_api::updateUserPrivacySettingRules::ID): { return "updateUserPrivacySettingRules"; }
        case (td::td_api::updateUsersNearby::ID): { return "updateUsersNearby"; }
        case (td::td_api::updateUserStatus::ID): { return "updateUserStatus"; }


        case (td::td_api::accountTtl::ID): { return "accountTtl"; }
        case (td::td_api::addedReaction::ID): { return "addedReaction"; }
        case (td::td_api::addedReactions::ID): { return "addedReactions"; }
        case (td::td_api::address::ID): { return "address"; }
        case (td::td_api::animatedChatPhoto::ID): { return "animatedChatPhoto"; }
        case (td::td_api::animatedEmoji::ID): { return "animatedEmoji"; }
        case (td::td_api::animation::ID): { return "animation"; }
        case (td::td_api::animations::ID): { return "animations"; }
        case (td::td_api::audio::ID): { return "audio"; }
        case (td::td_api::authenticationCodeInfo::ID): { return "authenticationCodeInfo"; }

        case (td::td_api::authenticationCodeTypeTelegramMessage::ID): { return "authenticationCodeTypeTelegramMessage"; }
        case (td::td_api::authenticationCodeTypeSms::ID): { return "authenticationCodeTypeSms"; }
        case (td::td_api::authenticationCodeTypeCall::ID): { return "authenticationCodeTypeCall"; }
        case (td::td_api::authenticationCodeTypeFlashCall::ID): { return "authenticationCodeTypeFlashCall"; }
        case (td::td_api::authenticationCodeTypeMissedCall::ID): { return "authenticationCodeTypeMissedCall"; }
        case (td::td_api::autoDownloadSettings::ID): { return "autoDownloadSettings"; }
        case (td::td_api::autoDownloadSettingsPresets::ID): { return "autoDownloadSettingsPresets"; }
        case (td::td_api::availableReactions::ID): { return "availableReactions"; }
        case (td::td_api::background::ID): { return "background"; }

        case (td::td_api::backgroundFillSolid::ID): { return "backgroundFillSolid"; }
        case (td::td_api::backgroundFillGradient::ID): { return "backgroundFillGradient"; }
        case (td::td_api::backgroundFillFreeformGradient::ID): { return "backgroundFillFreeformGradient"; }


        case (td::td_api::backgroundTypeWallpaper::ID): { return "backgroundTypeWallpaper"; }
        case (td::td_api::backgroundTypePattern::ID): { return "backgroundTypePattern"; }
        case (td::td_api::backgroundTypeFill::ID): { return "backgroundTypeFill"; }

        case (td::td_api::backgrounds::ID): { return "backgrounds"; }
        case (td::td_api::bankCardActionOpenUrl::ID): { return "bankCardActionOpenUrl"; }
        case (td::td_api::bankCardInfo::ID): { return "bankCardInfo"; }
        case (td::td_api::basicGroup::ID): { return "basicGroup"; }
        case (td::td_api::basicGroupFullInfo::ID): { return "basicGroupFullInfo"; }
        case (td::td_api::botCommand::ID): { return "botCommand"; }

        case (td::td_api::botCommandScopeDefault::ID): { return "botCommandScopeDefault"; }
        case (td::td_api::botCommandScopeAllPrivateChats::ID): { return "botCommandScopeAllPrivateChats"; }
        case (td::td_api::botCommandScopeAllChatAdministrators::ID): { return "botCommandScopeAllChatAdministrators"; }
        case (td::td_api::botCommandScopeChat::ID): { return "botCommandScopeChat"; }
        case (td::td_api::botCommandScopeChatAdministrators::ID): { return "botCommandScopeChatAdministrators"; }
        case (td::td_api::botCommandScopeChatMember::ID): { return "botCommandScopeChatMember"; }

        case (td::td_api::botCommands::ID): { return "botCommands"; }
        case (td::td_api::call::ID): { return "call"; }

        // case (td::td_api::CallDiscardReason::ID): { return "CallDiscardReason"; }
        case (td::td_api::callDiscardReasonEmpty::ID): { return "callDiscardReasonEmpty"; }
        case (td::td_api::callDiscardReasonMissed::ID): { return "callDiscardReasonMissed"; }
        case (td::td_api::callDiscardReasonDeclined::ID): { return "callDiscardReasonMissed"; }
        case (td::td_api::callDiscardReasonDisconnected::ID): { return "callDiscardReasonDisconnected"; }
        case (td::td_api::callDiscardReasonHungUp::ID): { return "callDiscardReasonHungUp"; }

        case (td::td_api::callId::ID): { return "callId"; }
        // case (td::td_api::CallProblem::ID): { return "CallProblem"; }
        case (td::td_api::callProtocol::ID): { return "callProtocol"; }
        case (td::td_api::callServer::ID): { return "callServer"; }
        // case (td::td_api::CallServerType::ID): { return "CallServerType"; }
        // case (td::td_api::CallState::ID): { return "CallState"; }
        case (td::td_api::callbackQueryAnswer::ID): { return "callbackQueryAnswer"; }
        // case (td::td_api::CallbackQueryPayload::ID): { return "CallbackQueryPayload"; }
        // case (td::td_api::CanTransferOwnershipResult::ID): { return "CanTransferOwnershipResult"; }
        case (td::td_api::chat::ID): { return "chat"; }
        // case (td::td_api::ChatAction::ID): { return "ChatAction"; }
        // case (td::td_api::ChatActionBar::ID): { return "ChatActionBar"; }
        case (td::td_api::chatAdministrator::ID): { return "chatAdministrator"; }
        case (td::td_api::chatAdministrators::ID): { return "chatAdministrators"; }
        case (td::td_api::chatEvent::ID): { return "chatEvent"; }
        // case (td::td_api::ChatEventAction::ID): { return "ChatEventAction"; }
        case (td::td_api::chatEventLogFilters::ID): { return "chatEventLogFilters"; }
        case (td::td_api::chatEvents::ID): { return "chatEvents"; }
        case (td::td_api::chatFilter::ID): { return "chatFilter"; }
        case (td::td_api::chatFilterInfo::ID): { return "chatFilterInfo"; }
        case (td::td_api::chatInviteLink::ID): { return "chatInviteLink"; }
        case (td::td_api::chatInviteLinkCount::ID): { return "chatInviteLinkCount"; }
        case (td::td_api::chatInviteLinkCounts::ID): { return "chatInviteLinkCounts"; }
        case (td::td_api::chatInviteLinkInfo::ID): { return "chatInviteLinkInfo"; }
        case (td::td_api::chatInviteLinkMember::ID): { return "chatInviteLinkMember"; }
        case (td::td_api::chatInviteLinkMembers::ID): { return "chatInviteLinkMembers"; }
        case (td::td_api::chatInviteLinks::ID): { return "chatInviteLinks"; }
        case (td::td_api::chatJoinRequest::ID): { return "chatJoinRequest"; }
        case (td::td_api::chatJoinRequests::ID): { return "chatJoinRequests"; }
        case (td::td_api::chatJoinRequestsInfo::ID): { return "chatJoinRequestsInfo"; }
        // case (td::td_api::ChatList::ID): { return "ChatList"; }
        case (td::td_api::chatLists::ID): { return "chatLists"; }
        case (td::td_api::chatLocation::ID): { return "chatLocation"; }
        case (td::td_api::chatMember::ID): { return "chatMember"; }
        // case (td::td_api::ChatMemberStatus::ID): { return "ChatMemberStatus"; }
        case (td::td_api::chatMembers::ID): { return "chatMembers"; }
        // case (td::td_api::ChatMembersFilter::ID): { return "ChatMembersFilter"; }
        case (td::td_api::chatNearby::ID): { return "chatNearby"; }
        case (td::td_api::chatNotificationSettings::ID): { return "chatNotificationSettings"; }
        case (td::td_api::chatPermissions::ID): { return "chatPermissions"; }
        case (td::td_api::chatPhoto::ID): { return "chatPhoto"; }
        case (td::td_api::chatPhotoInfo::ID): { return "chatPhotoInfo"; }
        case (td::td_api::chatPhotos::ID): { return "chatPhotos"; }
        case (td::td_api::chatPosition::ID): { return "chatPosition"; }
        // case (td::td_api::ChatReportReason::ID): { return "ChatReportReason"; }
        // case (td::td_api::ChatSource::ID): { return "ChatSource"; }
        // case (td::td_api::ChatStatistics::ID): { return "ChatStatistics"; }
        case (td::td_api::chatStatisticsAdministratorActionsInfo::ID): { return "chatStatisticsAdministratorActionsInfo"; }
        case (td::td_api::chatStatisticsInviterInfo::ID): { return "chatStatisticsInviterInfo"; }
        case (td::td_api::chatStatisticsMessageInteractionInfo::ID): { return "chatStatisticsMessageInteractionInfo"; }
        case (td::td_api::chatStatisticsMessageSenderInfo::ID): { return "chatStatisticsMessageSenderInfo"; }
        case (td::td_api::chatTheme::ID): { return "chatTheme"; }
        // case (td::td_api::ChatType::ID): { return "ChatType"; }
        case (td::td_api::chats::ID): { return "chats"; }
        case (td::td_api::chatsNearby::ID): { return "chatsNearby"; }
        // case (td::td_api::CheckChatUsernameResult::ID): { return "CheckChatUsernameResult"; }
        // case (td::td_api::CheckStickerSetNameResult::ID): { return "CheckStickerSetNameResult"; }
        case (td::td_api::closedVectorPath::ID): { return "closedVectorPath"; }
        case (td::td_api::connectedWebsite::ID): { return "connectedWebsite"; }
        case (td::td_api::connectedWebsites::ID): { return "connectedWebsites"; }
        // case (td::td_api::ConnectionState::ID): { return "ConnectionState"; }
        case (td::td_api::contact::ID): { return "contact"; }
        case (td::td_api::count::ID): { return "count"; }
        case (td::td_api::countries::ID): { return "countries"; }
        case (td::td_api::countryInfo::ID): { return "countryInfo"; }
        case (td::td_api::customRequestResult::ID): { return "customRequestResult"; }
        case (td::td_api::databaseStatistics::ID): { return "databaseStatistics"; }
        case (td::td_api::date::ID): { return "date"; }
        case (td::td_api::dateRange::ID): { return "dateRange"; }
        case (td::td_api::datedFile::ID): { return "datedFile"; }
        case (td::td_api::deepLinkInfo::ID): { return "deepLinkInfo"; }
        // case (td::td_api::DeviceToken::ID): { return "DeviceToken"; }
        // case (td::td_api::DiceStickers::ID): { return "DiceStickers"; }
        case (td::td_api::document::ID): { return "document"; }
        case (td::td_api::downloadedFileCounts::ID): { return "downloadedFileCounts"; }
        case (td::td_api::draftMessage::ID): { return "draftMessage"; }
        case (td::td_api::emailAddressAuthenticationCodeInfo::ID): { return "emailAddressAuthenticationCodeInfo"; }
        case (td::td_api::emojis::ID): { return "emojis"; }
        case (td::td_api::encryptedCredentials::ID): { return "encryptedCredentials"; }
        case (td::td_api::encryptedPassportElement::ID): { return "encryptedPassportElement"; }
        case (td::td_api::file::ID): { return "file"; }
        case (td::td_api::fileDownload::ID): { return "fileDownload"; }
        case (td::td_api::filePart::ID): { return "filePart"; }
        // case (td::td_api::FileType::ID): { return "FileType"; }
        case (td::td_api::formattedText::ID): { return "formattedText"; }
        case (td::td_api::foundFileDownloads::ID): { return "foundFileDownloads"; }
        case (td::td_api::foundMessages::ID): { return "foundMessages"; }
        case (td::td_api::game::ID): { return "game"; }
        case (td::td_api::gameHighScore::ID): { return "gameHighScore"; }
        case (td::td_api::gameHighScores::ID): { return "gameHighScores"; }
        case (td::td_api::groupCall::ID): { return "groupCall"; }
        case (td::td_api::groupCallId::ID): { return "groupCallId"; }
        case (td::td_api::groupCallParticipant::ID): { return "groupCallParticipant"; }
        case (td::td_api::groupCallParticipantVideoInfo::ID): { return "groupCallParticipantVideoInfo"; }
        case (td::td_api::groupCallRecentSpeaker::ID): { return "groupCallRecentSpeaker"; }
        case (td::td_api::groupCallStream::ID): { return "groupCallStream"; }
        case (td::td_api::groupCallStreams::ID): { return "groupCallStreams"; }
        // case (td::td_api::GroupCallVideoQuality::ID): { return "GroupCallVideoQuality"; }
        case (td::td_api::groupCallVideoSourceGroup::ID): { return "groupCallVideoSourceGroup"; }
        case (td::td_api::hashtags::ID): { return "hashtags"; }
        case (td::td_api::httpUrl::ID): { return "httpUrl"; }
        case (td::td_api::identityDocument::ID): { return "identityDocument"; }
        case (td::td_api::importedContacts::ID): { return "importedContacts"; }
        case (td::td_api::inlineKeyboardButton::ID): { return "inlineKeyboardButton"; }
        // case (td::td_api::InlineKeyboardButtonType::ID): { return "InlineKeyboardButtonType"; }
        // case (td::td_api::InlineQueryResult::ID): { return "InlineQueryResult"; }
        case (td::td_api::inlineQueryResults::ID): { return "inlineQueryResults"; }
        // case (td::td_api::InputBackground::ID): { return "InputBackground"; }
        // case (td::td_api::InputChatPhoto::ID): { return "InputChatPhoto"; }
        // case (td::td_api::InputCredentials::ID): { return "InputCredentials"; }
        // case (td::td_api::InputFile::ID): { return "InputFile"; }
        case (td::td_api::inputIdentityDocument::ID): { return "inputIdentityDocument"; }
        // case (td::td_api::InputInlineQueryResult::ID): { return "InputInlineQueryResult"; }
        // case (td::td_api::InputMessageContent::ID): { return "InputMessageContent"; }
        // case (td::td_api::InputPassportElement::ID): { return "InputPassportElement"; }
        case (td::td_api::inputPassportElementError::ID): { return "inputPassportElementError"; }
        // case (td::td_api::InputPassportElementErrorSource::ID): { return "InputPassportElementErrorSource"; }
        case (td::td_api::inputPersonalDocument::ID): { return "inputPersonalDocument"; }
        case (td::td_api::inputSticker::ID): { return "inputSticker"; }
        case (td::td_api::inputThumbnail::ID): { return "inputThumbnail"; }
        // case (td::td_api::InternalLinkType::ID): { return "InternalLinkType"; }
        case (td::td_api::invoice::ID): { return "invoice"; }
        case (td::td_api::jsonObjectMember::ID): { return "jsonObjectMember"; }
        // case (td::td_api::JsonValue::ID): { return "JsonValue"; }
        case (td::td_api::keyboardButton::ID): { return "keyboardButton"; }
        // case (td::td_api::KeyboardButtonType::ID): { return "KeyboardButtonType"; }
        case (td::td_api::labeledPricePart::ID): { return "labeledPricePart"; }
        case (td::td_api::languagePackInfo::ID): { return "languagePackInfo"; }
        case (td::td_api::languagePackString::ID): { return "languagePackString"; }
        // case (td::td_api::LanguagePackStringValue::ID): { return "LanguagePackStringValue"; }
        case (td::td_api::languagePackStrings::ID): { return "languagePackStrings"; }
        case (td::td_api::localFile::ID): { return "localFile"; }
        case (td::td_api::localizationTargetInfo::ID): { return "localizationTargetInfo"; }
        case (td::td_api::location::ID): { return "location"; }
        // case (td::td_api::LogStream::ID): { return "LogStream"; }
        case (td::td_api::logTags::ID): { return "logTags"; }
        case (td::td_api::logVerbosityLevel::ID): { return "logVerbosityLevel"; }
        // case (td::td_api::LoginUrlInfo::ID): { return "LoginUrlInfo"; }
        // case (td::td_api::MaskPoint::ID): { return "MaskPoint"; }
        case (td::td_api::maskPosition::ID): { return "maskPosition"; }
        case (td::td_api::message::ID): { return "message"; }
        case (td::td_api::messageCalendar::ID): { return "messageCalendar"; }
        case (td::td_api::messageCalendarDay::ID): { return "messageCalendarDay"; }
        // case (td::td_api::MessageContent::ID): { return "MessageContent"; }
        case (td::td_api::messageCopyOptions::ID): { return "messageCopyOptions"; }
        // case (td::td_api::MessageFileType::ID): { return "MessageFileType"; }
        case (td::td_api::messageForwardInfo::ID): { return "messageForwardInfo"; }
        // case (td::td_api::MessageForwardOrigin::ID): { return "MessageForwardOrigin"; }
        case (td::td_api::messageInteractionInfo::ID): { return "messageInteractionInfo"; }
        case (td::td_api::messageLink::ID): { return "messageLink"; }
        case (td::td_api::messageLinkInfo::ID): { return "messageLinkInfo"; }
        case (td::td_api::messagePosition::ID): { return "messagePosition"; }
        case (td::td_api::messagePositions::ID): { return "messagePositions"; }
        case (td::td_api::messageReaction::ID): { return "messageReaction"; }
        case (td::td_api::messageReplyInfo::ID): { return "messageReplyInfo"; }
        // case (td::td_api::MessageSchedulingState::ID): { return "MessageSchedulingState"; }
        case (td::td_api::messageSendOptions::ID): { return "messageSendOptions"; }
        // case (td::td_api::MessageSender::ID): { return "MessageSender"; }
        case (td::td_api::messageSenders::ID): { return "messageSenders"; }
        // case (td::td_api::MessageSendingState::ID): { return "MessageSendingState"; }
        case (td::td_api::messageStatistics::ID): { return "messageStatistics"; }
        case (td::td_api::messageThreadInfo::ID): { return "messageThreadInfo"; }
        case (td::td_api::messages::ID): { return "messages"; }
        case (td::td_api::minithumbnail::ID): { return "minithumbnail"; }
        case (td::td_api::networkStatistics::ID): { return "networkStatistics"; }
        // case (td::td_api::NetworkStatisticsEntry::ID): { return "NetworkStatisticsEntry"; }
        // case (td::td_api::NetworkType::ID): { return "NetworkType"; }
        case (td::td_api::notification::ID): { return "notification"; }
        case (td::td_api::notificationGroup::ID): { return "notificationGroup"; }
        // case (td::td_api::NotificationGroupType::ID): { return "NotificationGroupType"; }
        // case (td::td_api::NotificationSettingsScope::ID): { return "NotificationSettingsScope"; }
        // case (td::td_api::NotificationType::ID): { return "NotificationType"; }
        // case (td::td_api::OptionValue::ID): { return "OptionValue"; }
        case (td::td_api::orderInfo::ID): { return "orderInfo"; }
        // case (td::td_api::PageBlock::ID): { return "PageBlock"; }
        case (td::td_api::pageBlockCaption::ID): { return "pageBlockCaption"; }
        // case (td::td_api::PageBlockHorizontalAlignment::ID): { return "PageBlockHorizontalAlignment"; }
        case (td::td_api::pageBlockListItem::ID): { return "pageBlockListItem"; }
        case (td::td_api::pageBlockRelatedArticle::ID): { return "pageBlockRelatedArticle"; }
        case (td::td_api::pageBlockTableCell::ID): { return "pageBlockTableCell"; }
        // case (td::td_api::PageBlockVerticalAlignment::ID): { return "PageBlockVerticalAlignment"; }
        case (td::td_api::passportAuthorizationForm::ID): { return "passportAuthorizationForm"; }
        // case (td::td_api::PassportElement::ID): { return "PassportElement"; }
        case (td::td_api::passportElementError::ID): { return "passportElementError"; }
        // case (td::td_api::PassportElementErrorSource::ID): { return "PassportElementErrorSource"; }
        // case (td::td_api::PassportElementType::ID): { return "PassportElementType"; }
        case (td::td_api::passportElements::ID): { return "passportElements"; }
        case (td::td_api::passportElementsWithErrors::ID): { return "passportElementsWithErrors"; }
        case (td::td_api::passportRequiredElement::ID): { return "passportRequiredElement"; }
        case (td::td_api::passportSuitableElement::ID): { return "passportSuitableElement"; }
        case (td::td_api::passwordState::ID): { return "passwordState"; }
        case (td::td_api::paymentForm::ID): { return "paymentForm"; }
        case (td::td_api::paymentFormTheme::ID): { return "paymentFormTheme"; }
        case (td::td_api::paymentReceipt::ID): { return "paymentReceipt"; }
        case (td::td_api::paymentResult::ID): { return "paymentResult"; }
        case (td::td_api::paymentsProviderStripe::ID): { return "paymentsProviderStripe"; }
        case (td::td_api::personalDetails::ID): { return "personalDetails"; }
        case (td::td_api::personalDocument::ID): { return "personalDocument"; }
        case (td::td_api::phoneNumberAuthenticationSettings::ID): { return "phoneNumberAuthenticationSettings"; }
        case (td::td_api::phoneNumberInfo::ID): { return "phoneNumberInfo"; }
        case (td::td_api::photo::ID): { return "photo"; }
        case (td::td_api::photoSize::ID): { return "photoSize"; }
        case (td::td_api::point::ID): { return "point"; }
        case (td::td_api::poll::ID): { return "poll"; }
        case (td::td_api::pollOption::ID): { return "pollOption"; }
        // case (td::td_api::PollType::ID): { return "PollType"; }
        case (td::td_api::profilePhoto::ID): { return "profilePhoto"; }
        case (td::td_api::proxies::ID): { return "proxies"; }
        case (td::td_api::proxy::ID): { return "proxy"; }
        // case (td::td_api::ProxyType::ID): { return "ProxyType"; }
        // case (td::td_api::PublicChatType::ID): { return "PublicChatType"; }
        // case (td::td_api::PushMessageContent::ID): { return "PushMessageContent"; }
        case (td::td_api::pushReceiverId::ID): { return "pushReceiverId"; }
        case (td::td_api::reaction::ID): { return "reaction"; }
        case (td::td_api::recommendedChatFilter::ID): { return "recommendedChatFilter"; }
        case (td::td_api::recommendedChatFilters::ID): { return "recommendedChatFilters"; }
        case (td::td_api::recoveryEmailAddress::ID): { return "recoveryEmailAddress"; }
        case (td::td_api::remoteFile::ID): { return "remoteFile"; }
        // case (td::td_api::ReplyMarkup::ID): { return "ReplyMarkup"; }
        // case (td::td_api::ResetPasswordResult::ID): { return "ResetPasswordResult"; }
        // case (td::td_api::RichText::ID): { return "RichText"; }
        case (td::td_api::rtmpUrl::ID): { return "rtmpUrl"; }
        case (td::td_api::savedCredentials::ID): { return "savedCredentials"; }
        case (td::td_api::scopeNotificationSettings::ID): { return "scopeNotificationSettings"; }
        // case (td::td_api::SearchMessagesFilter::ID): { return "SearchMessagesFilter"; }
        case (td::td_api::seconds::ID): { return "seconds"; }
        case (td::td_api::secretChat::ID): { return "secretChat"; }
        // case (td::td_api::SecretChatState::ID): { return "SecretChatState"; }
        case (td::td_api::session::ID): { return "session"; }
        case (td::td_api::sessions::ID): { return "sessions"; }
        case (td::td_api::shippingOption::ID): { return "shippingOption"; }
        case (td::td_api::sponsoredMessage::ID): { return "sponsoredMessage"; }
        // case (td::td_api::StatisticalGraph::ID): { return "StatisticalGraph"; }
        case (td::td_api::statisticalValue::ID): { return "statisticalValue"; }
        case (td::td_api::sticker::ID): { return "sticker"; }
        case (td::td_api::stickerSet::ID): { return "stickerSet"; }
        case (td::td_api::stickerSetInfo::ID): { return "stickerSetInfo"; }
        case (td::td_api::stickerSets::ID): { return "stickerSets"; }
        // case (td::td_api::StickerType::ID): { return "StickerType"; }
        case (td::td_api::stickers::ID): { return "stickers"; }
        case (td::td_api::storageStatistics::ID): { return "storageStatistics"; }
        case (td::td_api::storageStatisticsByChat::ID): { return "storageStatisticsByChat"; }
        case (td::td_api::storageStatisticsByFileType::ID): { return "storageStatisticsByFileType"; }
        case (td::td_api::storageStatisticsFast::ID): { return "storageStatisticsFast"; }
        // case (td::td_api::SuggestedAction::ID): { return "SuggestedAction"; }
        case (td::td_api::supergroup::ID): { return "supergroup"; }
        case (td::td_api::supergroupFullInfo::ID): { return "supergroupFullInfo"; }
        // case (td::td_api::SupergroupMembersFilter::ID): { return "SupergroupMembersFilter"; }
        case (td::td_api::tMeUrl::ID): { return "tMeUrl"; }
        // case (td::td_api::TMeUrlType::ID): { return "TMeUrlType"; }
        case (td::td_api::tMeUrls::ID): { return "tMeUrls"; }
        case (td::td_api::tdlibParameters::ID): { return "tdlibParameters"; }
        case (td::td_api::temporaryPasswordState::ID): { return "temporaryPasswordState"; }
        case (td::td_api::termsOfService::ID): { return "termsOfService"; }
        case (td::td_api::testBytes::ID): { return "testBytes"; }
        case (td::td_api::testInt::ID): { return "testInt"; }
        case (td::td_api::testString::ID): { return "testString"; }
        case (td::td_api::testVectorInt::ID): { return "testVectorInt"; }
        case (td::td_api::testVectorIntObject::ID): { return "testVectorIntObject"; }
        case (td::td_api::testVectorString::ID): { return "testVectorString"; }
        case (td::td_api::testVectorStringObject::ID): { return "testVectorStringObject"; }
        case (td::td_api::text::ID): { return "text"; }
        case (td::td_api::textEntities::ID): { return "textEntities"; }
        case (td::td_api::textEntity::ID): { return "textEntity"; }
        // case (td::td_api::TextEntityType::ID): { return "TextEntityType"; }
        // case (td::td_api::TextParseMode::ID): { return "TextParseMode"; }
        case (td::td_api::themeSettings::ID): { return "themeSettings"; }
        case (td::td_api::thumbnail::ID): { return "thumbnail"; }
        // case (td::td_api::ThumbnailFormat::ID): { return "ThumbnailFormat"; }
        // case (td::td_api::TopChatCategory::ID): { return "TopChatCategory"; }
        case (td::td_api::unreadReaction::ID): { return "unreadReaction"; }
        // case (td::td_api::Update::ID): { return "Update"; }
        case (td::td_api::updates::ID): { return "updates"; }
        case (td::td_api::user::ID): { return "user"; }
        case (td::td_api::userFullInfo::ID): { return "userFullInfo"; }
        // case (td::td_api::UserPrivacySetting::ID): { return "UserPrivacySetting"; }
        // case (td::td_api::UserPrivacySettingRule::ID): { return "UserPrivacySettingRule"; }
        case (td::td_api::userPrivacySettingRules::ID): { return "userPrivacySettingRules"; }
        // case (td::td_api::UserStatus::ID): { return "UserStatus"; }
        // case (td::td_api::UserType::ID): { return "UserType"; }
        case (td::td_api::users::ID): { return "users"; }
        case (td::td_api::validatedOrderInfo::ID): { return "validatedOrderInfo"; }
        // case (td::td_api::VectorPathCommand::ID): { return "VectorPathCommand"; }




        default: { return "\'UNKNOWN Id to Name binding\' typeid: " + std::to_string(t_id); }
    };
}

} // namespace log
} // namespace tdlpp
#endif // tdlpp_IdNameBinding